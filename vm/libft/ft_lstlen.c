/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:23:55 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/10 11:12:36 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list **alst)
{
	t_list	*elem;
	size_t	i;

	if ((alst == NULL) || (*alst == NULL))
		return (0);
	elem = *alst;
	i = 0;
	while (elem != 0)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}
