/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:23:23 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/08 11:23:24 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

void	ft_asm_print_error(t_asm_valid params)
{
	(void)params;
	ft_printf("ERROR: line = %d pos = %d\n", params.line_nb, params.char_nb);
}

void	ft_asm_init_regex(t_regex (*regex_funcs)[19])
{
	(*regex_funcs)[0] = ft_asm_regex_empty_line;
	(*regex_funcs)[1] = ft_asm_regex_champ_comment;
	(*regex_funcs)[2] = ft_asm_regex_champ_name;
	(*regex_funcs)[3] = ft_asm_regex_and;
	(*regex_funcs)[4] = ft_asm_regex_ld;
	(*regex_funcs)[5] = ft_asm_regex_st;
	(*regex_funcs)[6] = ft_asm_regex_add;
	(*regex_funcs)[7] = ft_asm_regex_sub;
	(*regex_funcs)[8] = ft_asm_regex_live;
	(*regex_funcs)[9] = ft_asm_regex_or;
	(*regex_funcs)[10] = ft_asm_regex_xor;
	(*regex_funcs)[11] = ft_asm_regex_zjmp;
	(*regex_funcs)[12] = ft_asm_regex_ldi;
	(*regex_funcs)[13] = ft_asm_regex_sti;
	(*regex_funcs)[14] = ft_asm_regex_fork;
	(*regex_funcs)[15] = ft_asm_regex_lld;
	(*regex_funcs)[16] = ft_asm_regex_lldi;
	(*regex_funcs)[17] = ft_asm_regex_lfork;
	(*regex_funcs)[18] = ft_asm_regex_aff;
}

void		ft_init_params(t_asm_valid *params)
{
	ft_bzero(params, sizeof(t_asm_valid));
	params->line_nb = 1;
	params->char_nb = 1;
	params->line_count = 1;
	params->labels = ft_al_init(0, sizeof(void*));
	params->labels_args = ft_al_init(0, sizeof(void*));
}

int 		main(int ac, char **av)
{
	char		*champ;
	char		*result;
	t_regex		regex_funcs[19];
	t_asm_valid	params;

	ft_init_params(&params);

	if (ac == 1 && ft_printf("Usage: \n"))
		return (0);

	if ((champ = ft_asm_read_file(&params, av[1])) == NULL
		&& ft_printf("No such file\n"))
		return (0);
	ft_asm_init_regex(&regex_funcs);
	if (ft_asm_valid(&params, regex_funcs, champ) && ft_asm_labels_matching(&params))
	{
		char **trimmed = ft_strsplit(champ, '\n');
		char **for_trim = trimmed;
		while (*for_trim)
		{
			*for_trim = ft_strtrim(*for_trim);
			for_trim++;
		}
		params.len_for_write = get_bytecode(&result, trimmed);
		int fd = open("test.cor", O_WRONLY | O_CREAT, 0777);
		write(fd, result, (size_t)params.len_for_write);
	}
	else
		ft_asm_print_error(params);
	ft_strdel(&champ);

	return (0);
}
