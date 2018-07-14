/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:06:09 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:17:14 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	ft_base(int d)
{
	char	*strbase;

	strbase = "0123456789ABCDEF";
	return (strbase[d]);
}

static void	ft_itoa_base_1(uintmax_t n, uintmax_t base, char *str, int *i)
{
	if (n >= base)
	{
		ft_itoa_base_1(n / base, base, str, i);
		ft_itoa_base_1(n % base, base, str, i);
	}
	else
		str[(*i)++] = ft_base(n);
}

static void	ft_itoa_base_0(intmax_t n, intmax_t base, char *str, int *i)
{
	if (n == -9223372036854775807 - 1)
	{
		if (base == 10)
			str[(*i)++] = '-';
		str[(*i)++] = '9';
		n = 223372036854775808;
	}
	if (n < 0)
	{
		if (base == 10)
			str[(*i)++] = '-';
		n = -n;
	}
	if (n >= base)
	{
		ft_itoa_base_0(n / base, base, str, i);
		ft_itoa_base_0(n % base, base, str, i);
	}
	else
		str[(*i)++] = ft_base(n);
}

char		*ft_itoa_base_u(intmax_t n, int base, int b)
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
	str = (char *)malloc(sizeof(char) * (ft_ordernum_base_u(n, base, b) + 1));
	i = 0;
	if (b)
		ft_itoa_base_1(n, base, str, &i);
	else
		ft_itoa_base_0(n, base, str, &i);
	str[i] = '\0';
	return (str);
}
