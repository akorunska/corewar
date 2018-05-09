/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:32:12 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/27 08:13:10 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static	int		compare(char *str, const char *to_find, size_t cur, size_t n)
{
	size_t	j;
	int		match;

	j = 0;
	match = 0;
	while (to_find[j] == str[j] && to_find[j] != '\0')
	{
		j++;
		if (++cur > n)
			return (0);
		match = 1;
	}
	if (to_find[j] != '\0')
		match = 0;
	return (match);
}

char			*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	char		*first;
	size_t		i;
	int			match;

	if (to_find[0] == '\0')
		return ((char *)str);
	first = 0;
	i = 0;
	match = 0;
	while (str[i] != '\0' && i < n && !match)
	{
		if (str[i] == to_find[0])
		{
			first = (char *)str + i;
			match = compare(first, to_find, i, n);
		}
		i++;
	}
	if (match)
		return (first);
	return (0);
}
