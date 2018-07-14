/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:18:11 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/01 17:18:13 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	int		i;
	int		start;

	if (s != 0)
	{
		i = 0;
		while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
			i++;
		start = i;
		while (s[i] != '\0')
			i++;
		if (i != start)
			while ((s[i - 1] == ' ') || (s[i - 1] == '\n')
				|| (s[i - 1] == '\t'))
				i--;
		tmp = (char*)malloc(sizeof(char) * (i - start + 1));
		if (tmp == 0)
			return (0);
		tmp[i - start] = '\0';
		while ((i-- > start - 1))
			tmp[i - start] = s[i];
		return (tmp);
	}
	return (0);
}
