/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:25:13 by igaliuk           #+#    #+#             */
/*   Updated: 2017/10/30 20:25:15 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*tmp;
	unsigned int		i;

	if ((s != 0) && (f != 0))
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		tmp = (char*)malloc(sizeof(char) * (i + 1));
		if (tmp == 0)
			return (0);
		i = 0;
		while (s[i] != '\0')
		{
			tmp[i] = (*f)(i, s[i]);
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (0);
}
