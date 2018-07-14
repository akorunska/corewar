/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_regex_aff_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:14:56 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/22 17:14:57 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

t_handle_func	ft_asm_regex_aff_reg(char **str, int *res, t_asm_valid *params)
{
	size_t	len;
	char	*str_cpy;

	(void)params;
	ft_asm_skip_symb(str, res);
	len = 0;
	str_cpy = *str;
	while (*str_cpy && ft_isdigit(*str_cpy))
	{
		len++;
		str_cpy++;
	}
	if (len > 0 && len < 3)
	{
		while (len--)
			ft_asm_skip_symb(str, res);
		return ((void*)ft_asm_regex_finish);
	}
	return (NULL);
}
