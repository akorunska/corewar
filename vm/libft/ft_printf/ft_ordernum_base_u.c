/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ordernum_base_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:06:41 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:17:24 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_ordernum_base_u(intmax_t d, int base, int b)
{
	int			i;
	uintmax_t	du;

	i = 0;
	du = (uintmax_t)d;
	if (b)
		while (du)
		{
			du /= base;
			i++;
		}
	else
		while (d)
		{
			d /= base;
			i++;
		}
	return (i);
}
