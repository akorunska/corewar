/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:13:56 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/08 12:13:57 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

int		ft_asm_valid_line(t_regex funcs[19], char *champ, t_asm_valid *params)
{
	int	res;
	int temp;
	int	i;

	res = -1;
	i = -1;
	while (++i < 19)
	{
		if ((temp = funcs[i](champ, params)) != -1)
		{
			if (temp > res)
				res = temp;
		}
		else
			return (-1);
	}
	return (res);
}

void	ft_asm_valid_skip_lines(t_asm_valid *params, char **champ)
{
	if (params->nl_in_name > 0)
		while (params->nl_in_name--)
			(*champ) = ft_strchr(*champ, '\n') + 1;
	if (params->nl_in_comment > 0)
		while (params->nl_in_comment--)
			(*champ) = ft_strchr(*champ, '\n') + 1;
}

bool	ft_asm_valid(t_asm_valid *params, t_regex funcs[19], char *champ)
{
	int	i;

	i = -1;
	params->line_nb = 1;
	while (++i < params->line_count)
	{
		params->char_nb = ft_asm_valid_line(funcs, champ, params);
		if (params->char_nb != -1)
			return (0);
		if (params->nl_in_name > 0 || params->nl_in_comment > 0)
			ft_asm_valid_skip_lines(params, &champ);
		champ = ft_strchr(champ, '\n') + 1;
		(params->line_nb)++;
		params->char_nb = 1;
	}
	if (params->name == 1 && params->comment == 1)
		return (1);
	return (0);
}
