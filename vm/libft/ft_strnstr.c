/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:17:27 by igaliuk           #+#    #+#             */
/*   Updated: 2017/10/26 16:17:29 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	j = 0;
	k = 0;
	if (little[j] == '\0')
		return (&(((char*)big)[k]));
	while ((big[++i] != '\0') && (i <= len - 1) && (j <= len - 1) && (len != 0))
	{
		if (big[i] == little[j])
		{
			if (j++ == 0)
				k = i;
		}
		else
		{
			i = i - j;
			j = 0;
		}
		if (little[j] == '\0')
			return (&(((char*)big)[k]));
	}
	return (NULL);
}
