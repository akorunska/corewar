/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmapchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:48:59 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/18 10:49:01 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkmapchar(char *dst, char *src)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	while (dst[i] != '\0')
	{
		b = 0;
		j = 0;
		while (src[j] != '\0')
		{
			if ((dst[i] == src[j]) || (dst[i] == '\n'))
				b = 1;
			j++;
		}
		if (b == 0)
			return (0);
		i++;
	}
	return (1);
}
