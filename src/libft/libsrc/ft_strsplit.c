/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:26:42 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/28 17:53:38 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *str, char c)
{
	char	cur_ch;
	char	next_ch;
	int		i;
	int		res;

	i = 0;
	res = 0;
	cur_ch = str[0];
	next_ch = str[1];
	while (cur_ch != '\0')
	{
		if (c != cur_ch && (c == next_ch || next_ch == '\0'))
			res++;
		i++;
		cur_ch = next_ch;
		next_ch = str[i];
	}
	return (res);
}

static int	count_w_len(char *str, char c)
{
	int		res;

	res = 0;
	while (c != str[res] && str[res] != '\0')
		res++;
	return (res);
}

static void	word_cpy(char *src, char *dest, char c)
{
	int i;

	i = 0;
	while (c != src[i] && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static char	**free_all(char **w_list, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(w_list[i]);
		i++;
	}
	free(w_list);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		cur_w_len;
	int		w_found;
	char	**w_list;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	w_list = (char **)ft_memalloc(sizeof(char *) * (count_words(s, c) + 1));
	w_found = 0;
	while (w_list && w_found < count_words(s, c))
	{
		cur_w_len = count_w_len(str, c);
		if (cur_w_len > 0)
		{
			w_list[w_found] = (char *)malloc(sizeof(char*) * (cur_w_len + 1));
			if (!w_list[w_found])
				return (free_all(w_list, w_found));
			word_cpy(str, w_list[w_found++], c);
			str += cur_w_len;
		}
		str += 1;
	}
	return (w_list);
}
