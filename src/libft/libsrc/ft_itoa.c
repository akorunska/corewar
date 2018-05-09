/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:37:56 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/29 17:52:02 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int n)
{
	int res;

	res = 1;
	if (n < 0)
	{
		n = -n;
		res++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char		*res;
	int			len;
	long int	l_n;

	len = count_digits(n);
	l_n = (long int)n;
	l_n = (l_n > 0) ? (l_n) : (-l_n);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (len > 0)
	{
		len--;
		res[len] = l_n % 10 + '0';
		l_n /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
