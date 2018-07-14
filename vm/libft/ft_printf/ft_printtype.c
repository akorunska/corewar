/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:11:57 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:15:03 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_printstr_list(char **str, t_pers par, void *s)
{
	t_list	*begin;
	t_list	*tmp;
	int		len;
	int		i;

	begin = NULL;
	len = 0;
	i = 0;
	while (((int *)s)[i])
	{
		if (!(tmp = ft_lstnew(NULL, 0)))
			return (-1);
		len += ft_numsbits((char **)(&(tmp->content)), ((int *)s)[i]);
		if ((par.pr != -1) && (len > par.pr))
		{
			ft_lstdelone(&tmp, &ft_del);
			break ;
		}
		ft_lstaddback(&begin, tmp);
		i++;
	}
	if (!(*str = ft_lsttostr(&begin, len)))
		return (-1);
	return (0);
}

int		ft_printstr(char **str, t_pers par, void *s)
{
	if (!s)
	{
		if (!(*str = ft_strdup("(null)")))
			return (-1);
		return (0);
	}
	if (par.ln == 3)
		return (ft_printstr_list(str, par, s));
	else
	{
		if (!(*str = ft_strdup((char *)s)))
			return (-1);
		return (0);
	}
}

int		ft_printptr(char **str, void *p)
{
	if (!p)
	{
		if (!(*str = ft_strdup("0")))
			return (-1);
		return (0);
	}
	if (!(*str = ft_itoa_base_u((unsigned long long)p, 16, 1)))
		return (-1);
	ft_aaff(str);
	return (0);
}

int		ft_printchr(char **str, t_pers par, void *c, size_t *zlo)
{
	if (MB_CUR_MAX == 1)
		par.ln = 0;
	if (!c)
	{
		*zlo = 666;
		if (!(*str = ft_strnew(1)))
			return (-1);
		(*str)[0] = '@';
		return (0);
	}
	if (par.ln == 3)
		return (ft_numsbits(str, (int)c));
	else
	{
		if (!(*str = ft_strnew(1)))
			return (-1);
		(*str)[0] = (unsigned char)c;
		return (0);
	}
}
