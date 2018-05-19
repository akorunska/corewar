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

static char	ft_get_symb(uintmax_t *n, int base)
{
	char	res;

	res = *n % base + '0';
	*n /= base;
	if (res > '9')
		return (res + 39);
	return (res);
}

static int	ft_input_size(uintmax_t n, int base)
{
	int		counter;

	counter = 1;
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

char		*ft_itoa_base_unsign(uintmax_t n, int base)
{
	char	*res;
	int		i;
	int		size;

	if (base < 2 || base > 16)
		return (NULL);
	size = ft_input_size(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	while (i++ < size)
		res[i] = ft_get_symb(&n, base);
	*(res + size) = '\0';
	ft_reverse_str(res);
	return (res);
}
