/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:36:26 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/03 18:36:28 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmplst;
	t_list	*newlst;
	t_list	*begin_newlst;

	if ((lst != 0) && (f != 0))
	{
		tmplst = lst;
		newlst = (t_list*)malloc(sizeof(t_list));
		if (newlst == 0)
			return (0);
		newlst = (*f)(tmplst);
		begin_newlst = newlst;
		while (tmplst->next != NULL)
		{
			tmplst = tmplst->next;
			newlst->next = (t_list*)malloc(sizeof(t_list));
			if (newlst->next == 0)
				return (0);
			newlst->next = (*f)(tmplst);
			newlst = newlst->next;
		}
		return (begin_newlst);
	}
	return (0);
}
