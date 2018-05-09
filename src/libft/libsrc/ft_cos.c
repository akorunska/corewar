/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:59:32 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/30 13:19:33 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_cos(double x)
{
	double	res;
	int		n;
	int		k;

	n = 0;
	res = 0.0;
	k = 1;
	while (n < 6)
	{
		res += (k * (double)ft_power(x, 2 * n)) / ft_factorial(2 * n);
		k *= -1;
		n++;
	}
	return (res);
}
