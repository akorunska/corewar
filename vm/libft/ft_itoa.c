/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:44:07 by igaliuk           #+#    #+#             */
/*   Updated: 2017/10/30 16:44:12 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_putnbr(int n, char *s, int *i)
{
	if (n == -2147483648)
	{
		s[(*i)++] = '-';
		s[(*i)++] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		s[(*i)++] = '-';
		n = -n;
	}
	if ((n / 10) > 0)
	{
		ft_itoa_putnbr(n / 10, s, i);
		ft_itoa_putnbr(n % 10, s, i);
	}
	else
		s[(*i)++] = n + '0';
	s[*i] = '\0';
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		j;
	int		m;

	i = 0;
	j = 0;
	m = n;
	if (m <= 0)
		j++;
	while ((m < 0) || (m > 0))
	{
		m = m / 10;
		j++;
	}
	s = (char*)malloc(sizeof(char) * (j + 1));
	if (s == 0)
		return (0);
	ft_itoa_putnbr(n, s, &i);
	return (s);
}
