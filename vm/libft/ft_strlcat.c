/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:44:35 by igaliuk           #+#    #+#             */
/*   Updated: 2017/10/26 19:44:37 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ki;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	ki = i;
	while ((src[j] != '\0') && ((i + 1) < size))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	while (src[j] != '\0')
		j++;
	if (ki >= size)
		return (j + size);
	return (ki + j);
}
