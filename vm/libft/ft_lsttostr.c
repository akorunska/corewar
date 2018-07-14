/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:01:18 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/14 15:23:21 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lsttostr(t_list **begin, size_t len)
{
	t_list	*tmp;
	char	*str;

	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	tmp = *begin;
	while (tmp)
	{
		ft_strcat(str, tmp->content);
		tmp = tmp->next;
	}
	ft_lstdel(begin, &ft_del);
	return (str);
}
