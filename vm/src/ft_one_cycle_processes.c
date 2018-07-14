/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_cycle_processes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:52:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/08 16:11:49 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_one_cycle_processes(t_mem *mem, t_info_players *info)
{
	t_list_proc		*tmp_lst_proc;

	tmp_lst_proc = mem->lst_proc;
	while (tmp_lst_proc)
	{
		if (!tmp_lst_proc->command)
			ft_add_command_to_process_or_not(mem, tmp_lst_proc);
		if (tmp_lst_proc->freeze > 0)
			tmp_lst_proc->freeze--;
		if (tmp_lst_proc->command && !tmp_lst_proc->freeze)
		{
			ft_execution_command(mem, info, tmp_lst_proc);
			ft_zero_command_and_args_in_proc(tmp_lst_proc);
		}
		if (mem->visual)
			mem->str_mem_inv[tmp_lst_proc->position] = 1;
		tmp_lst_proc = tmp_lst_proc->next;
	}
}

void	ft_add_command_to_process_or_not(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	int		i;

	if (mem->str_mem[tmp_lst_proc->position] >= 1
		&& mem->str_mem[tmp_lst_proc->position] <= 16)
	{
		i = 0;
		while (g_op_tab[i].opcode)
		{
			if (g_op_tab[i].opcode == mem->str_mem[tmp_lst_proc->position])
			{
				tmp_lst_proc->freeze = g_op_tab[i].cycles;
				tmp_lst_proc->command = g_op_tab[i].opcode;
				tmp_lst_proc->index_command = i;
				break ;
			}
			i++;
		}
	}
	else
		tmp_lst_proc->position = (++tmp_lst_proc->position) % MEM_SIZE;
}
