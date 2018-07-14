/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:14:44 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/10 21:41:00 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/vm.h"

int		ft_zjmp(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	(void)mem;
	if (tmp_lst_proc->carry)
	{
		tmp_lst_proc->position += tmp_lst_proc->args_value[0] % IDX_MOD;
		while (tmp_lst_proc->position < 0)
			tmp_lst_proc->position += MEM_SIZE;
		tmp_lst_proc->position %= MEM_SIZE;
	}
	return (0);
}
