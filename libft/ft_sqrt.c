/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:50:50 by ddenkin           #+#    #+#             */
/*   Updated: 2018/02/24 19:01:03 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	f(double w, double g)
{
	return (g * g - w);
}

static double	fprime(double g)
{
	return (2 * g);
}

static int		closeenough(double a, double b)
{
	return (ft_fabs(a - b) < ft_fabs(b * 0.0001));
}

static double	findroot(double w, double g)
{
	double	newguess;

	newguess = g - f(w, g) / fprime(g);
	if (closeenough(newguess, g))
		return (newguess);
	else
		return (findroot(w, newguess));
}

double			ft_sqrt(double x)
{
	return (findroot(x, 1));
}
