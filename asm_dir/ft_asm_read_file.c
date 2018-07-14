/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_read_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:41:54 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/14 15:41:56 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

char		*ft_asm_read_file(t_asm_valid *params, char *filename)
{
	int		fd;
	char	*res;
	char	*cpy;
	char	buf[READ_SIZE];

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	res = ft_strnew(0);
	ft_bzero(buf, READ_SIZE);
	while (read(fd, buf, READ_SIZE) > 0)
	{
		cpy = res;
		res = ft_strjoin(res, buf);
		ft_strdel(&cpy);
		ft_bzero(buf, READ_SIZE);
	}
	close(fd);
	cpy = res;
	while (*cpy)
	{
		if (*cpy == '\n')
			params->line_count++;
		cpy++;
	}
	return (res);
}
