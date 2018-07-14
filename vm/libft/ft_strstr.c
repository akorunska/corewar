/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:17:37 by igaliuk           #+#    #+#             */
/*   Updated: 2017/10/26 16:17:40 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	if (little[j] == '\0')
		return (&(((char*)big)[k]));
	while (big[++i] != '\0')
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
