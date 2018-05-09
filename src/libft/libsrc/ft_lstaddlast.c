/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:52:58 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/30 11:53:39 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddlast(t_list *lst, t_list *new)
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
