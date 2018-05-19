/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:45:28 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/23 20:14:52 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(uint64_t n, int base)
{
	int					i;
	uint64_t			temp;

	i = 0;
	temp = n;
	while ((temp /= base) > 0)
		i++;
	return (i + 1);
}

static char	*myutoa(uint64_t n, int size, int base)
{
	int					i;
	int					end;
	uint64_t			temp;
	char				*res;

	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size] = '\0';
	end = 0;
	temp = n;
	i = size;
	while (--i >= end)
	{
		res[i] = (temp % base < 10) ? (temp % base) + 48 : (temp % base) + 87;
		temp /= base;
	}
	return (res);
}

char		*ft_utoa_base(uint64_t n, int base)
{
	int		size;
	char	*res;

	size = count_size(n, base);
	res = myutoa(n, size, base);
	return (res);
}
