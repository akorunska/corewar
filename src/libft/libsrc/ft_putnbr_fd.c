/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:32:21 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/29 16:14:08 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putlongnbr_fd(long int n, int fd)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n / 10 > 0)
	{
		ft_putlongnbr_fd(n / 10, fd);
	}
	ft_putchar_fd('0' + n % 10, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	ft_putlongnbr_fd(n, fd);
}
