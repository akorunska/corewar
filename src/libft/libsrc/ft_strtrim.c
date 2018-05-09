/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:42:21 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/29 18:50:13 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(char const *s)
{
	int		i;
	int		len;
	char	*end;

	len = ft_strlen(s);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (len - i);
	end = ft_strchr(s, '\0') - 1;
	while ((*end == ' ' || *end == '\t' || *end == '\n') && end != s)
	{
		end--;
		i++;
	}
	return (len - i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = ft_strnew(count_len(s));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	ft_strcpy(ptr, s + i);
	i = ft_strlen(ptr) - 1;
	while (ptr[i] == ' ' || ptr[i] == '\t' || ptr[i] == '\n')
	{
		ptr[i] = '\0';
		i--;
	}
	return (ptr);
}
