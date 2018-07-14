/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:14:11 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/07 18:14:21 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/vm.h"

int		ft_sub(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	(void)mem;
	tmp_lst_proc->reg[tmp_lst_proc->args_value[2] - 1] = tmp_lst_proc->
		reg[tmp_lst_proc->args_value[0] - 1] - tmp_lst_proc->
		reg[tmp_lst_proc->args_value[1] - 1];
	tmp_lst_proc->carry = ft_carry_0_or_1(tmp_lst_proc->
		reg[tmp_lst_proc->args_value[2] - 1]);
	return (0);
}
