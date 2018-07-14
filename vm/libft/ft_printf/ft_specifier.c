/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:08:54 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:16:25 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_flags_null(t_pers *par)
{
	(*par).ss = 0;
	(*par).fl1 = 0;
	(*par).fl2 = 0;
	(*par).fl3 = 0;
	(*par).fl4 = 0;
	(*par).fl5 = 0;
	(*par).wd = 0;
	(*par).pr = -1;
	(*par).ln = 0;
	(*par).tp = 0;
}

void	ft_order(int *t, const char *fmt, t_pers *par)
{
	int		start;

	start = *t;
	if (fmt[*t] != '*')
		(*par).ss = ft_orderfieldprec(t, fmt, NULL);
	if (fmt[*t] == '$')
		(*t)++;
	else
	{
		*t = start;
		(*par).ss = 0;
	}
}

void	ft_flags(int *t, const char *fmt, t_pers *par)
{
	if (fmt[*t] == '#')
		(*par).fl1 = 1;
	if ((fmt[*t] == '0') && !((*par).fl3))
		(*par).fl2 = 1;
	if (fmt[*t] == '-')
	{
		(*par).fl3 = 1;
		if ((*par).fl2 == 1)
			(*par).fl2 = 0;
	}
	if ((fmt[*t] == ' ') && !((*par).fl5))
		(*par).fl4 = 1;
	if (fmt[*t] == '+')
	{
		(*par).fl5 = 1;
		if ((*par).fl4 == 1)
			(*par).fl4 = 0;
	}
	if ((fmt[*t] == '#') || (fmt[*t] == '0') || (fmt[*t] == '-')
		|| (fmt[*t] == ' ') || (fmt[*t] == '+'))
		(*t)++;
}

int		ft_orderfieldprec(int *t, const char *fmt, t_valist *lstva)
{
	int		start;
	int		res;

	if (fmt[*t] == '*')
	{
		(*t)++;
		return (va_arg((*lstva).arg, int));
	}
	res = 0;
	start = *t;
	while ((fmt[*t] >= '0') && (fmt[*t] <= '9'))
		(*t)++;
	while (start != *t)
		res = 10 * res + fmt[start++] - '0';
	return (res);
}
