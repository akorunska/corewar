/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:58:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/17 17:50:04 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_execution_command(t_mem *mem, t_info_players *info,
								t_list_proc *tmp_lst_proc)
{
	int		step;
	int		ret;

	step = 1 + ft_codage_octal(mem, tmp_lst_proc);
	if (!ft_get_args_from_memory(mem, tmp_lst_proc, &step))
	{
		if ((ret = g_op_arr_of_com[tmp_lst_proc->
			index_command](mem, tmp_lst_proc)) == -1)
			ft_error_malloc(mem, info);
		if (mem->verb[2] && !mem->visual)
			ft_verb_4(mem, tmp_lst_proc);
		if (ret > 0)
		{
			if (mem->verb[0] && !mem->visual)
				ft_printf("Player %d (%s) is said to be alive\n",
					ret, info->binary_players[ret - 1].head->prog_name);
			info->live[ret - 1]++;
			info->last_live[ret - 1] = mem->total_cycles;
		}
		if (tmp_lst_proc->command == 9 && tmp_lst_proc->carry)
			step = 0;
	}
	if (mem->verb[4] && !mem->visual && step)
		ft_verb_16(mem, tmp_lst_proc, step);
	tmp_lst_proc->position = (tmp_lst_proc->position + step) % MEM_SIZE;
}

void	ft_zero_command_and_args_in_proc(t_list_proc *tmp_lst_proc)
{
	int		i;

	tmp_lst_proc->command = 0;
	tmp_lst_proc->index_command = 0;
	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		tmp_lst_proc->args_code[i] = 0;
		tmp_lst_proc->args_value[i++] = 0;
	}
}
