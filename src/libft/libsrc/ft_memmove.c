/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:36:26 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/27 10:06:17 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int	start_overlap(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char*)src;
	i = 0;
	while (i < (int)len)
	{
		if (ptr + i == dst)
			return (1);
		i++;
	}
	return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	if (start_overlap(dst, src, len))
	{
		i = len - 1;
		while (i >= 0)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			((unsigned char*)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
