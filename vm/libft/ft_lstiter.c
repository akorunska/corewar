/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:36:03 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/03 18:36:06 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmplst;

	if ((lst != 0) && (f != 0))
	{
		tmplst = lst;
		while (tmplst != 0)
		{
			(*f)(tmplst);
			tmplst = tmplst->next;
		}
	}
}
