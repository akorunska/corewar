/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_set_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:13:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/07 18:07:13 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_get_memory(char const *mem, int position, int size)
{
	int		tmp_value_memory;

	while (position < 0)
		position += MEM_SIZE;
	tmp_value_memory = 0;
	while (size > 0)
	{
		tmp_value_memory |= (unsigned char)mem[position++ % MEM_SIZE]
			<< (8 * (size - 1));
		size--;
	}
	return (tmp_value_memory);
}

int		ft_set_memory(char *mem, int position, int value)
{
	int		size;
	int		tmp_position;

	while (position < 0)
		position += MEM_SIZE;
	tmp_position = position;
	size = DIR_SIZE;
	while (size > 0)
	{
		mem[position++ % MEM_SIZE] = (char)((value >> (8 * (size - 1)))
			- (value >> (8 * (size - 1 + 1)) << 8));
		size--;
	}
	return (tmp_position);
}
