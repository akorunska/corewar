/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:37:35 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/12 17:37:37 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"
#include "../libftprintf/libftprintf.h"

t_labeled_code	*al_get_by_index(t_code_array_list *d, int index)
{
	if (index < 0 || index >= d->size)
		return (NULL);
	return (d->values[index]);
}

t_labeled_code	*al_get_by_label(t_code_array_list *d, char *label)
{
	int		i;

	i = -1;
	while (++i < d->size)
		if (!ft_strcmp(label, d->values[i]->label))
			return (d->values[i]);
	return (NULL);
}

void			al_map(t_code_array_list *self, void f(t_labeled_code *c))
{
	int		i;

	i = -1;
	while (++i < self->size)
	{
		f(self->values[i]);
	}
}

int				al_index_of(t_code_array_list *self, char *label)
{
	int		i;

	i = -1;
	while (++i < self->size)
	{
		if (!ft_strcmp(label, self->values[i]->label))
			return (i);
	}
	return (-1);
}

int				al_index_of_command(t_code_array_list *self, t_labeled_code *c)
{
	int		i;

	i = -1;
	while (++i < self->size)
	{
		if (c == self->values[i])
			return (i);
	}
	return (-1);
}
