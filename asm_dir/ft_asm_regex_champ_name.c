/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_regex_champ_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:37:46 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/08 18:37:47 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

t_handle_func	ft_asm_regex_name_start_quote(char **str, int *res,
												t_asm_valid *params)
{
	int		i;

	(void)params;
	ft_asm_skip_symb(str, res);
	i = -1;
	while (++i < PROG_NAME_LENGTH && **str && **str != '"')
	{
		if (**str == '\n')
		{
			params->line_count--;
			params->nl_in_name++;
			params->line_nb++;
			*res = 1;
			(*str)++;
		}
		else
			ft_asm_skip_symb(str, res);
	}
	if (**str && **str == '"')
	{
		ft_asm_skip_symb(str, res);
		return ((void*)ft_asm_regex_finish);
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_champ_name_before_quote(char **str, int *res,
														t_asm_valid *params)
{
	(void)params;
	while (**str && (**str == ' ' || **str == '\t'))
		ft_asm_skip_symb(str, res);
	if (**str == '"')
		return ((void*)ft_asm_regex_name_start_quote);
	return (NULL);
}

t_handle_func	ft_asm_regex_champ_name_start(char **str, int *res,
												t_asm_valid *params)
{
	int		len_name_string;
	int		i;

	(void)params;
	len_name_string = (int)ft_strlen(NAME_CMD_STRING);
	if (ft_strnequ(*str, NAME_CMD_STRING, (size_t)len_name_string) == 1)
	{
		i = -1;
		while (++i < len_name_string)
			ft_asm_skip_symb(str, res);
		return ((void*)(ft_asm_regex_champ_name_before_quote));
	}
	return (NULL);
}

int				ft_asm_regex_champ_name(char *champ, t_asm_valid *params)
{
	int				res;
	t_handle_func	func_curr;

	(void)params;
	func_curr = (t_handle_func)ft_asm_regex_champ_name_start;
	res = 1;
	while (*champ && (*champ == ' ' || *champ == '\t'))
		ft_asm_skip_symb(&champ, &res);
	while (*champ)
	{
		if (*func_curr == (void*)ft_asm_regex_success)
		{
			params->name++;
			return (-1);
		}
		else if (*func_curr == NULL)
			return (res);
		func_curr = (t_handle_func)func_curr(&champ, &res, params);
	}
	if (*(champ - 1) == '\n')
		return (-1);
	return (res);
}
