/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:21:43 by abodnar           #+#    #+#             */
/*   Updated: 2018/01/06 14:08:41 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_get_symb(intmax_t *n, int base)
{
	char	res;

	res = *n % base + '0';
	*n /= base;
	if (res > '9')
		return (res + 39);
	return (res);
}

static int	ft_input_size(intmax_t n, int base)
{
	int		counter;

	counter = ((n < 0 && base == 10) ? 2 : 1);
	while (n /= base)
		counter++;
	return (counter);
}

static void	ft_reverse_str(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

char		*ft_itoa_base_sign(intmax_t n, int base)
{
	char	*res;
	int		i;
	int		size;

	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_input_size(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (n < 0 && (n = n * -1) > 0)
		if (base == 10)
			*(res + size - 1) = '-';
	i = -1;
	while (i++ < size)
	{
		if (*(res + size - 1) == '-' && i == size - 1)
			break ;
		res[i] = ft_get_symb(&n, base);
	}
	*(res + size) = '\0';
	ft_reverse_str(res);
	return (res);
}
