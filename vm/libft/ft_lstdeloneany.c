/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeloneany.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:37:20 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/13 19:29:31 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeloneany(t_list **alst, t_list **clst,
	void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst && clst && del)
	{
		if (*alst == *clst)
		{
			ft_lstdelone(alst, ft_del);
			return ;
		}
		tmp = *alst;
		while (tmp->next)
		{
			if (tmp->next == *clst)
			{
				tmp->next = (*clst)->next;
				(*del)((*clst)->content, (*clst)->content_size);
				free(*clst);
				*clst = NULL;
				break ;
			}
			tmp = tmp->next;
		}
	}
}
