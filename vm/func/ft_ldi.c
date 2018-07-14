/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:14:56 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/07 18:14:57 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/vm.h"

int		ft_ldi(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	if (tmp_lst_proc->args_code[0] == REG_CODE)
		tmp_lst_proc->args_value[0] = tmp_lst_proc->
			reg[tmp_lst_proc->args_value[0] - 1];
	else if (tmp_lst_proc->args_code[0] == IND_CODE)
		tmp_lst_proc->args_value[0] = ft_get_memory(mem->str_mem, tmp_lst_proc->
			position + tmp_lst_proc->args_value[0] % IDX_MOD, DIR_SIZE);
	if (tmp_lst_proc->args_code[1] == REG_CODE)
		tmp_lst_proc->args_value[1] = tmp_lst_proc->
			reg[tmp_lst_proc->args_value[1] - 1];
	tmp_lst_proc->reg[tmp_lst_proc->
		args_value[2] - 1] = ft_get_memory(mem->str_mem, tmp_lst_proc->
		position + (tmp_lst_proc->args_value[0] + tmp_lst_proc->
		args_value[1]) % IDX_MOD, DIR_SIZE);
	return (0);
}
