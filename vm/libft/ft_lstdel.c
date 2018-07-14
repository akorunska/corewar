/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:36:53 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/13 16:57:10 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst && del)
	{
		while (*alst)
		{
			tmp = *alst;
			*alst = (*alst)->next;
			(*del)(tmp->content, tmp->content_size);
			free(tmp);
			tmp = NULL;
		}
		alst = NULL;
	}
}
