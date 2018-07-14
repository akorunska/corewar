/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wecha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:15:10 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:16:41 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_bitone(char **sb, int d)
{
	if (!(*sb = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	(*sb)[0] = d;
	(*sb)[1] = '\0';
	return (1);
}

int		ft_bittwo(char **sb, int d)
{
	if (!(*sb = (char *)malloc(sizeof(char) * 3)))
		return (-1);
	(*sb)[0] = 192 + ((d >> 6) & 63);
	(*sb)[1] = 128 + (d & 63);
	(*sb)[2] = '\0';
	return (2);
}

int		ft_bitthree(char **sb, int d)
{
	if (!(*sb = (char *)malloc(sizeof(char) * 4)))
		return (-1);
	(*sb)[0] = 224 + ((d >> 12) & 63);
	(*sb)[1] = 128 + ((d >> 6) & 63);
	(*sb)[2] = 128 + (d & 63);
	(*sb)[3] = '\0';
	return (3);
}

int		ft_bitfour(char **sb, int d)
{
	if (!(*sb = (char *)malloc(sizeof(char) * 5)))
		return (-1);
	(*sb)[0] = 240 + ((d >> 18) & 63);
	(*sb)[1] = 128 + ((d >> 12) & 63);
	(*sb)[2] = 128 + ((d >> 6) & 63);
	(*sb)[3] = 128 + (d & 63);
	(*sb)[4] = '\0';
	return (4);
}

int		ft_numsbits(char **sb, int d)
{
	if ((d >= 0) && (d <= 127))
		return (ft_bitone(sb, d));
	if ((d >= 128) && (d <= 2047))
		return (ft_bittwo(sb, d));
	if ((d >= 2048) && (d <= 65535))
		return (ft_bitthree(sb, d));
	if ((d >= 65535) && (d <= 1114111))
		return (ft_bitfour(sb, d));
	return (0);
}
