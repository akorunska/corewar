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
#include "../libft/libft.h"

void	al_initialise(t_array_list *al, int initial_capacity)
{
	int		i;

	al->size = 0;
	al->capacity = (initial_capacity >= 1) ? initial_capacity : 4;
	al->values = (t_labeled_code **)malloc(sizeof(t_labeled_code*) * al->capacity);
	i = 0;
	while (i < al->capacity)
	{
		al->values[i] = NULL;
		i++;
	}
}

static void	al_stretch(t_array_list *d)
{
	t_labeled_code		**bigger_copy;
    int 				i;

	bigger_copy = (t_labeled_code **)malloc(sizeof(t_labeled_code*) * 2 * d->capacity);
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

void	al_insert(t_array_list *d, char *lbl_name, t_op *op)
{
	if (d->size + 1 >= d->capacity)
		al_stretch(d);
	d->values[d->size] = (t_labeled_code *)malloc(sizeof(t_labeled_code));
	d->values[d->size]->label = (char *)malloc(sizeof(char) * ft_strlen(lbl_name));
	ft_strcpy(d->values[d->size]->label, lbl_name);
	d->values[d->size]->op = op;
	d->size++;
}

void	al_clear(t_array_list *d)
{
	int		i;

	i = 0;
	while (i < d->size)
	{
		ft_memdel((void**)&(d->values[i]->label));
		// somehow delete t_op contained in each element
		ft_memdel((void**)&(d->values[i]));
		i++;
	}
	ft_memdel((void**)&(d->values));
}

