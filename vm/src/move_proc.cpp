/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_proc.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:30:02 by ddenkin           #+#    #+#             */
/*   Updated: 2018/04/30 19:39:26 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	move_proc(t_core *c, t_proc *p, int i)
{
	c->f[p->index].occupied -= 1;
	p->index = (p->index + i) < 0 ? (p->index + i) % MEM_SIZE + MEM_SIZE: (p->index + i) % MEM_SIZE;
	c->f[p->index].occupied += 1;
}