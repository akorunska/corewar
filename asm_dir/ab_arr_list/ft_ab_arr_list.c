/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ab_arr_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:02:30 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/09 20:02:31 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ab_arr_list.h"

t_array_list	*ft_al_init(int init_capacity, size_t elem_size)
{
	t_array_list	*result;

	result = (t_array_list*)ft_memalloc(sizeof(t_array_list));
	result->size = 0;
	result->capacity = (init_capacity >= 1) ? init_capacity : 4;
	result->elem_size = elem_size;
	result->data = ft_memalloc(result->capacity * elem_size);
	return (result);
}

void			ft_al_stretch(t_array_list *al)
{
	void	**new_data;
	int		i;

	new_data = ft_memalloc(al->capacity * 2 * sizeof(void*));
	i = -1;
	while (++i < al->size)
		*((char**)new_data + i) = *((char**)(al->data) + i);
	al->capacity *= 2;
	ft_memdel((void**)&(al->data));
	al->data = new_data;
}

void			ft_al_insert(t_array_list *al, void *elem)
{
	if (al->size == al->capacity)
		ft_al_stretch(al);
	*((char**)al->data + al->size) = (char*)elem;
	al->size++;
}

void			ft_al_clear(t_array_list *al)
{
	int		i;

	i = -1;
	while (++i < al->size)
		free(*(al->data + i));
	free(al->data);
}
