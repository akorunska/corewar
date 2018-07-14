/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:40:32 by igaliuk           #+#    #+#             */
/*   Updated: 2017/10/30 18:40:38 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (tmp != NULL)
	{
		i = 0;
		while (i < size + 1)
		{
			tmp[i] = '\0';
			i++;
		}
	}
	return (tmp);
}
