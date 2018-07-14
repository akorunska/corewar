/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:51:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/07 18:07:13 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char		ft_arg_conv_type_to_code(t_arg_type t_arg)
{
	if (t_arg == T_REG)
		return (REG_CODE);
	if (t_arg == T_DIR)
		return (DIR_CODE);
	if (t_arg == T_IND)
		return (IND_CODE);
	return (0);
}

t_arg_type	ft_arg_conv_code_to_type(char arg)
{
	if (arg == REG_CODE)
		return (T_REG);
	if (arg == DIR_CODE)
		return (T_DIR);
	if (arg == IND_CODE)
		return (T_IND);
	return (0);
}
