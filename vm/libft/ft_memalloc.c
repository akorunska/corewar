/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:10:15 by igaliuk           #+#    #+#             */
/*   Updated: 2017/10/30 17:10:17 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*tmp;

	tmp = malloc(size);
	if (tmp == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		((unsigned char*)tmp)[i] = 0;
		i++;
	}
	return (tmp);
}
