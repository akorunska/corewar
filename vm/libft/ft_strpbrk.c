/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:52:47 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/04 18:52:50 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	if ((s1 == 0) || (s2 == 0))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return (&(((char*)s1)[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
