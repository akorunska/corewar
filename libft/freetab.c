/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:30:38 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/05 19:30:39 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		freetab(void ***tab, int size)
{
	int		i;

	i = 0;
	if (size <= 0)
		while ((*tab)[i] != NULL)
			free((*tab)[i++]);
	else
		while (i < size)
			free((*tab)[i++]);
	free(*tab);
	*tab = NULL;
}

int			freetabn(void ***tab, int size)
{
	freetab(tab, size);
	return (0);
}
