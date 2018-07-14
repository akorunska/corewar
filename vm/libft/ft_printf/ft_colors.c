/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:05:55 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:16:57 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_zerocol(t_col *col)
{
	col->col1 = "{eoc}{red}{green}{yellow}{blue}{magenta}{cyan}";
	col->col2 = "\e[0m\e[31m\e[32m\e[33m\e[34m\e[35m\e[36m";
}

int		ft_checkcolor(char *str, t_col *col)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (col->col1[i])
	{
		if (col->col1[i] == '{')
			start = i;
		if (col->col1[i] == '}')
		{
			if (!(ft_strncmp(str, col->col1 + start, i - start)))
			{
				col->size1 = i - start + 1;
				col->num = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

void	ft_writecolor(t_col *col)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j != col->num)
	{
		if (col->col2[i] == 'm')
			j++;
		i++;
	}
	j = i;
	while (col->col2[i] != 'm')
		i++;
	col->size2 = i - j + 1;
	write(1, col->col2 + j, col->size2);
}

int		ft_findcolors(int len, char *str)
{
	int		i;
	int		sumshift;
	t_col	col;

	ft_zerocol(&col);
	i = 0;
	sumshift = 0;
	while (i < len)
	{
		if ((str[i] == '{') && ((ft_checkcolor(str + i, &col)) != -1))
		{
			write(1, str, i);
			ft_writecolor(&col);
			str += i + col.size1;
			len -= i + col.size1;
			sumshift += col.size1 - col.size2;
			i = 0;
		}
		i++;
	}
	if (len)
		write(1, str, len);
	return (sumshift);
}
