/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writepersent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:07:32 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:16:45 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_realflags(char **str, t_pers par)
{
	char	*tmp;
	char	*src;

	src = NULL;
	tmp = *str;
	if ((par.fl1 && ((*str)[0] != '\0') && (par.tp == 'x')) || (par.tp == 'p'))
		src = "0x";
	if ((par.fl1 && ((*str)[0] != '\0') && (par.tp == 'X')))
		src = "0X";
	if (par.fl1 && (par.tp == 'o'))
		src = "0";
	if (par.fl4 && (par.tp == 'd') && (*str[0] != '-'))
		src = " ";
	if (par.fl5 && (par.tp == 'd') && (*str[0] != '-'))
		src = "+";
	if (!(*str = ft_strjoin(src, *str)))
		return (-1);
	ft_strdel(&tmp);
	return (0);
}

void	ft_width_0(char **str, t_pers par, int i)
{
	int		j;

	j = 0;
	if ((par.tp == 'p') || (par.fl1 && ((par.tp == 'x') || (par.tp == 'X'))))
	{
		(*str)[j++] = (*str)[i++];
		(*str)[j++] = (*str)[i++];
	}
	if (((*str)[i] == '-') || ((par.fl4 || par.fl5) && (par.tp == 'd')))
		(*str)[j++] = (*str)[i++];
	while (j < i)
		(*str)[j++] = '0';
}

int		ft_width(char **str, char **tmp, t_pers par, int *len)
{
	int		i;

	i = 0;
	if (!(*str = ft_strnew((size_t)(par.wd))))
		return (-1);
	if (par.fl3)
	{
		ft_strcpy(*str, *tmp);
		while (*len < par.wd)
			(*str)[(*len)++] = ' ';
		ft_strdel(tmp);
		return (0);
	}
	while (i < par.wd - *len)
		(*str)[i++] = ' ';
	ft_strcpy(*str + i, *tmp);
	ft_strdel(tmp);
	if ((par.pr != -1) && ((par.tp == 'd') || (par.tp == 'o')
		|| (par.tp == 'u') || (par.tp == 'x') || (par.tp == 'X')
		|| (par.tp == 'b') || (par.tp == 'p')))
		return (0);
	if (par.fl2)
		ft_width_0(str, par, i);
	return (0);
}

int		ft_writepersent(char **str, t_pers par)
{
	char	*tmp;
	int		len;

	len = (size_t)ft_strlen(*str);
	tmp = *str;
	if ((*str)[0] == '0')
		par.fl1 = 0;
	if (ft_precision(str, &tmp, par, len) == -1)
		return (-1);
	if (ft_realflags(str, par) == -1)
		return (-1);
	len = (size_t)ft_strlen(*str);
	tmp = *str;
	if (len < par.wd)
		if (ft_width(str, &tmp, par, &len) == -1)
			return (-1);
	return (0);
}
