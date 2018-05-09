/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:57:11 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/30 12:45:36 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_power(double nb, int power)
{
	double	res;
	int		cur_pow;

	res = nb;
	cur_pow = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (cur_pow < power)
	{
		res *= nb;
		cur_pow++;
	}
	return (res);
}
