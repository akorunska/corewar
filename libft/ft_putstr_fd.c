/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:05:03 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/16 21:31:53 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

static void	put(char *res, int *i, const char *toput)
{
	int		k;

	k = -1;
	while (toput[++k])
		res[*i + k] = toput[k];
	*i += k;
}

void		ft_rgbputstr_fd(char *str, int fd, unsigned int rgb, int bg)
{
	char	res[19];
	int		i;

	i = 0;
	put(res, &i, (bg == 0) ? "\e[38;2;" : "\e[48;2;");
	put(res, &i, ft_itoa(rgb >> 16 % 256));
	put(res, &i, ";");
	put(res, &i, ft_itoa(rgb << 16 >> 24 % 256));
	put(res, &i, ";");
	put(res, &i, ft_itoa(rgb % 256));
	put(res, &i, "m");
	res[i] = 0;
	ft_putstr_fd(res, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(COLOR_OFF, fd);
}
