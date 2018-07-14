/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttostrzlo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:06:20 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:17:20 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_lsttostrzlo(t_list **begin, int len)
{
	t_list	*tmp;
	char	*str;
	int		i;
	int		j;

	str = ft_strnew((size_t)len);
	if (str == NULL)
		return (NULL);
	tmp = *begin;
	i = 0;
	while (tmp)
	{
		j = 0;
		while (((char *)(tmp->content))[j])
		{
			str[i] = ((char *)(tmp->content))[j];
			if ((str[i] == '@') && (tmp->content_size))
				str[i] = '\0';
			i++;
			j++;
		}
		tmp = tmp->next;
	}
	ft_lstdel(begin, &ft_del);
	return (str);
}
