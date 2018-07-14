/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_persent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:08:21 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:16:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_length(int *t, const char *fmt, t_pers *par)
{
	if (fmt[*t] == 'h')
		par->ln = 2;
	if ((fmt[*t] == 'h') && (fmt[*t + 1] == 'h'))
		par->ln = 1;
	if (fmt[*t] == 'l')
		par->ln = 3;
	if ((fmt[*t] == 'l') && (fmt[*t + 1] == 'l'))
		par->ln = 4;
	if (fmt[*t] == 'j')
		par->ln = 5;
	if (fmt[*t] == 'z')
		par->ln = 6;
	if (fmt[*t] == 'L')
		par->ln = 7;
	if (par->ln)
		(*t)++;
	if ((par->ln == 1) || (par->ln == 4))
		(*t)++;
	if ((fmt[*t] == 'S') || (fmt[*t] == 'D') || (fmt[*t] == 'O')
		|| (fmt[*t] == 'U') || (fmt[*t] == 'B') || (fmt[*t] == 'C'))
		par->ln = 3;
}

void	ft_types(int *t, const char *fmt, t_pers *par)
{
	if ((fmt[*t] == 's') || (fmt[*t] == 'S'))
		par->tp = 's';
	if (fmt[*t] == 'p')
		par->tp = 'p';
	if ((fmt[*t] == 'd') || (fmt[*t] == 'D') || (fmt[*t] == 'i'))
		par->tp = 'd';
	if ((fmt[*t] == 'o') || (fmt[*t] == 'O'))
		par->tp = 'o';
	if ((fmt[*t] == 'u') || (fmt[*t] == 'U'))
		par->tp = 'u';
	if (fmt[*t] == 'x')
		par->tp = 'x';
	if (fmt[*t] == 'X')
		par->tp = 'X';
	if ((fmt[*t] == 'b') || (fmt[*t] == 'B'))
		par->tp = 'b';
	if ((fmt[*t] == 'c') || (fmt[*t] == 'C'))
		par->tp = 'c';
	if (par->tp)
		(*t)++;
}

void	ft_persent(int *t, const char *fmt, t_pers *par, t_valist *lstva)
{
	ft_flags_null(par);
	ft_order(t, fmt, par);
	while ((fmt[*t] == '#') || (fmt[*t] == '0') || (fmt[*t] == '-')
		|| (fmt[*t] == ' ') || (fmt[*t] == '+'))
		ft_flags(t, fmt, par);
	par->wd = ft_orderfieldprec(t, fmt, lstva);
	if (par->wd < 0)
	{
		par->wd = -par->wd;
		par->fl3 = 1;
	}
	if (fmt[*t] == '.')
	{
		(*t)++;
		par->pr = ft_orderfieldprec(t, fmt, lstva);
		if (par->pr < 0)
			par->pr = -1;
	}
	ft_length(t, fmt, par);
	ft_types(t, fmt, par);
}
