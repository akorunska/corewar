/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:05:35 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/30 12:24:27 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstadd_last(t_list *lst, t_list *new)
{
	t_list	*cur;

	cur = lst;
	if (!new)
		return (lst);
	else
		new->next = NULL;
	if (!lst)
		return (new);
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_node;
	t_list	*n_lst;

	n_lst = NULL;
	while (lst)
	{
		new_node = NULL;
		new_node = f(lst);
		if (new_node)
			n_lst = ft_lstadd_last(n_lst, new_node);
		lst = lst->next;
	}
	return (n_lst);
}
