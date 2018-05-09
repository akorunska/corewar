/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:58:40 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/30 13:09:03 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sin(double x)
{
	double	res;
	int		n;
	int		k;

	n = 0;
	res = 0.0;
	k = 1;
	while (n < 5)
	{
		res += (k * (double)ft_power(x, 2 * n + 1)) / ft_factorial(2 * n + 1);
		k *= -1;
		n++;
	}
	return (res);
}
