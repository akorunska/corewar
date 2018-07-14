/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:08:43 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:16:07 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_precisionss(char **str, char **tmp, t_pers par, int len)
{
	if (par.pr < len)
	{
		if (!(*str = ft_strsub(*tmp, 0, par.pr)))
			return (-1);
		ft_strdel(tmp);
	}
	return (0);
}

int		ft_precisiondiouxxbp(char **str, char **tmp, t_pers par, int len)
{
	int		i;

	if ((par.tp == 'o') && (par.fl1))
		par.pr--;
	if ((*tmp)[0] == '-')
		par.pr++;
	if (par.pr > len)
	{
		i = 0;
		if (!(*str = ft_strnew((size_t)(par.pr))))
			return (-1);
		if ((*tmp)[0] == '-')
		{
			(*str)[i++] = '-';
			**tmp = '0';
		}
		while (i < par.pr - len)
			(*str)[i++] = '0';
		ft_strcpy(*str + i, *tmp);
		ft_strdel(tmp);
	}
	return (0);
}

int		ft_precision(char **str, char **tmp, t_pers par, int len)
{
	if (par.pr != -1)
	{
		if (par.tp == 's')
			return (ft_precisionss(str, tmp, par, len));
		if ((par.tp == 'd') || (par.tp == 'o') || (par.tp == 'u')
			|| (par.tp == 'x') || (par.tp == 'X')
			|| (par.tp == 'b') || (par.tp == 'p'))
			return (ft_precisiondiouxxbp(str, tmp, par, len));
	}
	return (0);
}
