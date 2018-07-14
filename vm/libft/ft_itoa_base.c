/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:44:26 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/05 15:45:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_base(int d)
{
	char	*strbase;

	strbase = "0123456789ABCDEF";
	return (strbase[d]);
}

static void	ft_itoa_base_r(long long n, long long base, char *str, int *i)
{
	if (n < 0)
	{
		if (base == 10)
			str[(*i)++] = '-';
		n = -n;
	}
	if (n >= base)
	{
		ft_itoa_base_r(n / base, base, str, i);
		ft_itoa_base_r(n % base, base, str, i);
	}
	else
		str[(*i)++] = ft_base((int)n);
}

char		*ft_itoa_base(int n, int base)
{
	char	*str;
	int		i;

	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (ft_ordernum_base(n, base) + 1));
	i = 0;
	ft_itoa_base_r((long long)n, base, str, &i);
	str[i] = '\0';
	return (str);
}
