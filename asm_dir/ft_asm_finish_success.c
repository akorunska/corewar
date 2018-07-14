/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_finish_success.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:18:31 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/22 17:18:32 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

t_handle_func	ft_asm_regex_success(char **str, int *res, t_asm_valid *params)
{
	if (str && res && params)
		return (NULL);
	return (NULL);
}

t_handle_func	ft_asm_regex_finish(char **str, int *res, t_asm_valid *params)
{
	(void)params;
	while (**str && (**str == ' ' || **str == '\t'))
		ft_asm_skip_symb(str, res);
	if (**str == '\n')
		return ((void*)ft_asm_regex_success);
	else if (**str == COMMENT_CHAR || **str == COMMENT_CHAR_ADD)
	{
		ft_asm_skip_symb(str, res);
		while (**str && **str != '\n')
			ft_asm_skip_symb(str, res);
		if (**str == '\n')
			return ((void*)ft_asm_regex_success);
	}
	return (NULL);
}
