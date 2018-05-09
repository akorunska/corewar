/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 20:46:53 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/23 20:47:32 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		compare(char *str, const char *to_find)
{
	int j;
	int match;

	j = 0;
	match = 0;
	while (to_find[j] == str[j] && to_find[j] != '\0')
	{
		j++;
		match = 1;
	}
	if (to_find[j] != '\0')
		match = 0;
	return (match);
}

char			*ft_strstr(const char *str, const char *to_find)
{
	char	*first;
	int		i;
	int		match;

	if (to_find[0] == '\0')
		return ((char *)str);
	first = 0;
	i = 0;
	match = 0;
	while (str[i] != '\0' && !match)
	{
		if (str[i] == to_find[0])
		{
			first = (char *)str + i;
			match = compare(first, to_find);
		}
		i++;
	}
	if (match)
		return (first);
	return (0);
}
