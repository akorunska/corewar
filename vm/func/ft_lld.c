/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:11:41 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/07 18:11:42 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/vm.h"

int		ft_lld(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	if (tmp_lst_proc->args_code[0] == IND_CODE)
		tmp_lst_proc->reg[tmp_lst_proc->
			args_value[1] - 1] = ft_get_memory(mem->str_mem, tmp_lst_proc->
			position + tmp_lst_proc->args_value[0], DIR_SIZE / 2);
	else
		tmp_lst_proc->reg[tmp_lst_proc->args_value[1] - 1] = tmp_lst_proc->
			args_value[0];
	tmp_lst_proc->carry = ft_carry_0_or_1(tmp_lst_proc->
		reg[tmp_lst_proc->args_value[1] - 1]);
	return (0);
}
