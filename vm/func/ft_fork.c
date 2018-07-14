/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:14:02 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/17 17:40:47 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/vm.h"

int		ft_fork(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	t_list_proc	*new_lst_proc;
	int			i;
	int			tmp_position;

	tmp_position = tmp_lst_proc->position + tmp_lst_proc->args_value[0]
		% IDX_MOD;
	while (tmp_position < 0)
		tmp_position += MEM_SIZE;
	if (!(new_lst_proc = ft_lstprocnew(tmp_position
		% MEM_SIZE, tmp_lst_proc->pl)))
		return (-1);
	mem->lst_length++;
	i = 0;
	while (i < REG_NUMBER)
	{
		new_lst_proc->reg[i] = tmp_lst_proc->reg[i];
		i++;
	}
	new_lst_proc->alive = tmp_lst_proc->alive;
	new_lst_proc->carry = tmp_lst_proc->carry;
	new_lst_proc->last_live = tmp_lst_proc->last_live;
	ft_lstprocadd(&mem->lst_proc, new_lst_proc);
	return (0);
}
