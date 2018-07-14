/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:11:00 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/07 18:11:01 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/vm.h"

int		ft_aff(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	(void)mem;
	if (mem->aff && !mem->visual)
		ft_printf("%c\n", tmp_lst_proc->
			reg[tmp_lst_proc->args_value[0] - 1] % 256);
	return (0);
}
