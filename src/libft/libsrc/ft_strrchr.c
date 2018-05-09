/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:50:47 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/26 19:27:45 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *end;

	end = ft_strchr(s, '\0');
	while (end != s)
	{
		if (*end == c)
			return (end);
		end--;
	}
	if (*end == c)
		return (end);
	return (NULL);
}
