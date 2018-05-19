/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_regex_empty_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:28:21 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/08 18:28:22 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

int		ft_asm_regex_empty_line(char *champ, t_asm_valid *params)
{
	int	res;

	(void)params;
	res = 1;
	while (*champ && (*champ == ' ' || *champ == '\t'))
		ft_asm_skip_symb(&champ, &res);
	if (*champ == '\n')
		return (-1);
	else if (*champ == COMMENT_CHAR || *champ == COMMENT_CHAR_ADD)
	{
		ft_asm_skip_symb(&champ, &res);
		while (*champ && *champ != '\n')
			ft_asm_skip_symb(&champ, &res);
		if (*champ == '\n')
			return (-1);
	}
	return (res);
}
