/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 10:59:51 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/27 11:15:14 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret_ptr;
	size_t	i;

	ret_ptr = malloc(size);
	if (!ret_ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((unsigned char*)ret_ptr)[i] = 0;
		i++;
	}
	return (ret_ptr);
}
