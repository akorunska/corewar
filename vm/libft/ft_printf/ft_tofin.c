/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tofin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:07:58 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:16:32 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strchrlen(t_list **lstf)
{
	t_list	*tmp;
	size_t	len;

	tmp = *lstf;
	len = 0;
	while (tmp)
	{
		len += ft_strlen((char *)(tmp->content));
		tmp = tmp->next;
	}
	return (len);
}

int		ft_tofin(t_list **lstf, t_valist *lstva)
{
	char	*str;
	int		len;

	va_end((*lstva).arg);
	va_end((*lstva).arg_first);
	len = (int)ft_strchrlen(lstf);
	if (!(str = ft_lsttostrzlo(lstf, len)))
		return (-1);
	len -= ft_findcolors(len, str);
	ft_strdel(&str);
	return (len);
}
