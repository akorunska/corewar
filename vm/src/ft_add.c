/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:43:20 by ddenkin           #+#    #+#             */
/*   Updated: 2018/04/24 20:28:08 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_add(t_core *core, t_proc *proc)
{
	int	a;
	int	b;
	int	c;

	a = core->f[(proc->index + 2) % MEM_SIZE] - 1;
	b = core->f[(proc->index + 3) % MEM_SIZE] - 1;
	c = core->f[(proc->index + 4) % MEM_SIZE] - 1;
	if (a < 0 || b < 0 || c < 0 || a >= MEM_SIZE || b >= MEM_SIZE || c >=
																MEM_SIZE)
	{
		move_proc(core, proc, 5);
		return ;
	}
	proc->reg[c] = proc->reg[a] + proc->reg[b];
	proc->carry = (proc->reg[3]) ? 0 : 1;
	move_proc(core, proc, 5);
}
