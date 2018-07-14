/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmapsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:49:08 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/18 10:49:10 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkmapsize(char *dst, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (dst[i] != '\0')
	{
		j = 0;
		while (dst[i + j] != '\n')
			j++;
		if (j != x)
			return (0);
		i = i + j + 1;
		y--;
	}
	if (y != 0)
		return (0);
	return (1);
}
