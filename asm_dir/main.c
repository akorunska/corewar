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

void		ft_asm_init_regex(t_regex *regex_funcs)
{
	regex_funcs[0] = ft_asm_regex_empty_line;
	regex_funcs[1] = ft_asm_regex_champ_comment;
	regex_funcs[2] = ft_asm_regex_champ_name;
	regex_funcs[3] = ft_asm_regex_and;
	regex_funcs[4] = ft_asm_regex_ld;
	regex_funcs[5] = ft_asm_regex_st;
	regex_funcs[6] = ft_asm_regex_add;
	regex_funcs[7] = ft_asm_regex_sub;
	regex_funcs[8] = ft_asm_regex_live;
	regex_funcs[9] = ft_asm_regex_or;
	regex_funcs[10] = ft_asm_regex_xor;
	regex_funcs[11] = ft_asm_regex_zjmp;
	regex_funcs[12] = ft_asm_regex_ldi;
	regex_funcs[13] = ft_asm_regex_sti;
	regex_funcs[14] = ft_asm_regex_fork;
	regex_funcs[15] = ft_asm_regex_lld;
	regex_funcs[16] = ft_asm_regex_lldi;
	regex_funcs[17] = ft_asm_regex_lfork;
	regex_funcs[18] = ft_asm_regex_aff;
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

void		ft_asm_writing_champ(char *champ, char *filename,
											t_asm_valid *params)
{
	char	**lines;
	char	*fordel;
	int		i;
	int		fd;

	ft_printf("Writing output program to %s\n", filename);
	lines = ft_strsplit(champ, '\n');
	i = 0;
	while (lines[i])
	{
		fordel = lines[i];
		lines[i] = ft_strtrim(lines[i]);
		ft_strdel(&fordel);
		i++;
	}
	params->len_for_write = get_bytecode(&(params->result), lines);
	if ((fd = open(filename, O_WRONLY | O_CREAT, 0777)) != -1)
		write(fd, params->result, (size_t)params->len_for_write);
	close(fd);
	i = 0;
	while (lines[i])
		ft_strdel(&(lines[i++]));
	free(lines);
	ft_strdel(&filename);
}

char		*ft_asm_get_filename(char *arg)
{
	char	*work;
	char	*res;

	work = ft_strtrim(arg);
	if (ft_strequ(work + ft_strlen(work) - 2, ".s"))
	{
		res = ft_strsub(work, 0, ft_strlen(work) - 2);
		ft_strdel(&work);
		work = res;
		res = ft_strjoin(res, ".cor");
		ft_strdel(&work);
		return (res);
	}
	return (ft_strdup("..cor"));
}

int			main(int ac, char **av)
{
	char		*champ;
	t_regex		regex_funcs[19];
	t_asm_valid	params;

	ft_init_params(&params);
	if (ac != 2 && ft_printf("Usage: ./asm <sourcefile.s> \n"))
		return (0);
	if ((champ = ft_asm_read_file(&params, av[1])) == NULL
		&& ft_printf_fd(2, "ERROR: No such file\n"))
		return (0);
	ft_asm_init_regex(regex_funcs);
	if (ft_asm_valid(&params, regex_funcs, champ) &&
		ft_asm_labels_matching(&params))
		ft_asm_writing_champ(champ, ft_asm_get_filename(av[1]), &params);
	else
		ft_asm_print_error(params);
	ft_asm_clean_params(&params);
	ft_strdel(&champ);
	return (0);
}
