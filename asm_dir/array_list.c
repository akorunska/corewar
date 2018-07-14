/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:13:08 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/08 10:13:10 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"
#include <stdlib.h>
#include "../libftprintf/libftprintf.h"

void			al_initialise(t_code_array_list *al, int initial_capacity)
{
	int		i;

	al->size = 0;
	al->capacity = (initial_capacity >= 1) ? initial_capacity : 4;
	al->values = (t_labeled_code **)malloc(sizeof(t_labeled_code*) \
									* al->capacity);
	i = 0;
	while (i < al->capacity)
	{
		al->values[i] = NULL;
		i++;
	}
}

static void		al_stretch(t_code_array_list *d)
{
	t_labeled_code		**bigger_copy;
	int					i;

	bigger_copy = (t_labeled_code **)malloc(sizeof(t_labeled_code*) * \
	2 * d->capacity);
	i = 0;
	while (i < d->size)
	{
		bigger_copy[i] = d->values[i];
		i++;
	}
	d->capacity *= 2;
	free(d->values);
	d->values = bigger_copy;
}

void			al_insert(t_code_array_list *d, t_labeled_code *lc)
{
	if (!lc)
		return ;
	if (d->size + 1 >= d->capacity)
		al_stretch(d);
	d->values[d->size] = lc;
	d->size++;
}

void			al_clear(t_code_array_list *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->size)
	{
		if (d->values[i]->command)
		{
			ft_memdel((void**)&d->values[i]->bytecode);
			j = -1;
			while (d->values[i]->command->args[++j])
				ft_memdel((void**)&(d->values[i]->command->args[j]));
			ft_memdel((void**)&(d->values[i]->command->args));
			ft_memdel((void**)&(d->values[i]->command));
		}
		ft_memdel((void**)&(d->values[i]->label));
		ft_memdel((void**)&(d->values[i]));
		i++;
	}
	ft_memdel((void**)&(d->values));
}
