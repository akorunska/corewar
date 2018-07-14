/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:13:25 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/17 16:38:15 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/vm.h"

int		ft_st(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	int		i;
	int		tmp_position;

	if (tmp_lst_proc->args_code[1] == IND_CODE)
	{
		tmp_position = ft_set_memory(mem->str_mem, tmp_lst_proc->position
			+ tmp_lst_proc->args_value[1] % IDX_MOD, tmp_lst_proc->
			reg[tmp_lst_proc->args_value[0] - 1]);
		if (mem->visual)
		{
			i = 0;
			while (i < DIR_SIZE)
			{
				mem->str_mem_pl[(tmp_position + i)
					% MEM_SIZE] = tmp_lst_proc->pl;
				mem->str_mem_bold[(tmp_position + i++) % MEM_SIZE] = 49;
			}
		}
	}
	else
		tmp_lst_proc->reg[tmp_lst_proc->args_value[1] - 1] = tmp_lst_proc->
			reg[tmp_lst_proc->args_value[0] - 1];
	return (0);
}
