/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:11:18 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/17 16:21:40 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/vm.h"

int		ft_live(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	tmp_lst_proc->alive = 1;
	mem->sum_alive++;
	tmp_lst_proc->last_live = mem->total_cycles;
	if (tmp_lst_proc->args_value[0] >= 0 - mem->num_pl &&
			tmp_lst_proc->args_value[0] <= -1)
	{
		if (mem->visual)
		{
			mem->str_mem_inv[tmp_lst_proc->position] = 49;
			mem->str_mem_live[tmp_lst_proc->position] = 49;
		}
		return (mem->id_winner = 0 - tmp_lst_proc->args_value[0]);
	}
	return (0);
}
