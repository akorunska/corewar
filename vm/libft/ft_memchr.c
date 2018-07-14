/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:22:28 by igaliuk           #+#    #+#             */
/*   Updated: 2017/10/28 13:22:30 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (c < 0)
		c = c + 256;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == (c % 256))
			return (&(((unsigned char*)s)[i]));
		i++;
	}
	return (NULL);
}
