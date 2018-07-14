/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_print_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:30:20 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/22 12:30:21 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

int		ft_asm_print_error(t_asm_valid params)
{
	if (params.name != 1)
		ft_printf_fd(2, "ERROR: Incorrect number of names!\n");
	if (params.comment != 1)
		ft_printf_fd(2, "ERROR: Incorrect number of comments!\n");
	ft_printf_fd(2, "ERROR: line = %d pos = %d\n", params.line_nb,
															params.char_nb);
	return (1);
}
