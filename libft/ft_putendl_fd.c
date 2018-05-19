/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:09:18 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/16 15:43:19 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl_fd(char const *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

static void	put(char *res, int *i, const char *toput)
{
	int		k;

	k = -1;
	while (toput[++k])
		res[*i + k] = toput[k];
	*i += k;
}

void		ft_rgbputendl_fd(char *str, int fd, unsigned int rgb, int bg)
{
	char	res[19];
	int		i;

	i = 0;
	put(res, &i, (bg == 0) ? "\e[38;2;" : "\e[48;2;");
	put(res, &i, ft_itoa(rgb >> 16));
	put(res, &i, ";");
	put(res, &i, ft_itoa(rgb << 16 >> 24));
	put(res, &i, ";");
	put(res, &i, ft_itoa(rgb % 256));
	put(res, &i, "m");
	res[i] = 0;
	ft_putstr_fd(res, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(COLOR_OFF, fd);
	write(fd, "\n", 1);
}
