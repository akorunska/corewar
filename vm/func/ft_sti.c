/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:13:48 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/07 18:13:49 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/vm.h"

static void	ft_sti_visual(t_mem *mem, t_list_proc *tmp_lst_proc,
							int tmp_position)
{
	int		i;

	i = 0;
	while (i < DIR_SIZE)
	{
		mem->str_mem_pl[(tmp_position + i) % MEM_SIZE] = tmp_lst_proc->pl;
		mem->str_mem_bold[(tmp_position + i++) % MEM_SIZE] = 49;
	}
}

int			ft_sti(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	int		tmp_position;

	if (tmp_lst_proc->args_code[1] == REG_CODE)
		tmp_lst_proc->args_value[1] = tmp_lst_proc->
			reg[tmp_lst_proc->args_value[1] - 1];
	else if (tmp_lst_proc->args_code[1] == IND_CODE)
		tmp_lst_proc->args_value[1] = ft_get_memory(mem->str_mem,
			tmp_lst_proc->position + tmp_lst_proc->args_value[1]
			% IDX_MOD, DIR_SIZE);
	if (tmp_lst_proc->args_code[2] == REG_CODE)
		tmp_lst_proc->args_value[2] = tmp_lst_proc->
			reg[tmp_lst_proc->args_value[2] - 1];
	tmp_position = ft_set_memory(mem->str_mem, tmp_lst_proc->position
		+ (tmp_lst_proc->args_value[1] + tmp_lst_proc->args_value[2])
		% IDX_MOD, tmp_lst_proc->reg[tmp_lst_proc->args_value[0] - 1]);
	if (mem->visual)
		ft_sti_visual(mem, tmp_lst_proc, tmp_position);
	return (0);
}
