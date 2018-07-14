/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:11:40 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/04 19:30:40 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_zero_printf(t_list **lstf, t_pers *par)
{
	*lstf = NULL;
	(*par).t = 0;
}

int		ft_findpersent(t_list **lstf, int *t, const char *fmt)
{
	int		start;
	t_list	*tmp;

	start = *t;
	if (!(tmp = ft_lstnew(NULL, 0)))
		return (-1);
	while (fmt[*t])
	{
		if ((fmt[*t] == '%') && (fmt[*t + 1] == '\0'))
			return (2);
		if (fmt[*t] == '%')
		{
			tmp->content = ft_strsub(fmt, start, (*t - start));
			ft_lstaddback(lstf, tmp);
			(*t)++;
			return (1);
		}
		(*t)++;
	}
	if (tmp)
	{
		tmp->content = ft_strsub(fmt, start, (*t - start));
		ft_lstaddback(lstf, tmp);
	}
	return (0);
}

int		ft_needlines(t_list *tmp, t_pers *par, const char *fmt, t_valist *lstva)
{
	if (!(par->tp))
	{
		if (ft_printpct((char **)(&(tmp->content)), fmt[par->t++]) == -1)
			return (-1);
	}
	else
	{
		if (ft_second((char **)(&(tmp->content)), *par,
			lstva, &(tmp->content_size)) == -1)
			return (-1);
	}
	if ((ft_writepersent((char **)(&(tmp->content)), *par)) == -1)
		return (-1);
	return (0);
}

int		ft_errors(t_list **lstf)
{
	ft_lstdel(lstf, &ft_del);
	return (-1);
}

int		ft_printf(const char *fmt, ...)
{
	int			z;
	t_valist	lstva;
	t_pers		par;
	t_list		*lstf;
	t_list		*tmp;

	va_start(lstva.arg, fmt);
	va_copy(lstva.arg_first, lstva.arg);
	ft_zero_printf(&lstf, &par);
	while ((z = ft_findpersent(&lstf, &(par.t), fmt)) != 0)
	{
		if (z == -1)
			return (ft_errors(&lstf));
		if (z == 2)
			break ;
		if (!(tmp = ft_lstnew(NULL, 0)))
			return (ft_errors(&lstf));
		ft_persent(&(par.t), fmt, &par, &lstva);
		if ((ft_needlines(tmp, &par, fmt, &lstva)) == -1)
			return (ft_errors(&lstf));
		ft_lstaddback(&lstf, tmp);
	}
	return (ft_tofin(&lstf, &lstva));
}
