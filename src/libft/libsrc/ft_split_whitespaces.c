/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 02:23:23 by akorunsk          #+#    #+#             */
/*   Updated: 2017/08/05 22:41:13 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v')
		return (1);
	return (0);
}

int		count_words(char *str)
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
		if (!is_separator(cur_ch) && (is_separator(next_ch) || next_ch == '\0'))
			res++;
		i++;
		cur_ch = next_ch;
		next_ch = str[i];
	}
	return (res);
}

int		count_w_len(char *str)
{
	int		res;

	res = 0;
	while (!is_separator(str[res]) && str[res] != '\0')
		res++;
	return (res);
}

void	word_cpy(char *src, char *dest)
{
	int i;

	i = 0;
	while (!is_separator(src[i]) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split_whitespaces(char *str)
{
	int		w_quan;
	int		cur_w_len;
	int		w_found;
	char	**w_list;

	w_quan = count_words(str);
	w_list = (char **)malloc(sizeof(char *) * (w_quan + 1));
	w_found = 0;
	while (w_found < w_quan)
	{
		cur_w_len = count_w_len(str);
		if (cur_w_len > 0)
		{
			w_list[w_found] = (char *)malloc(sizeof(char*) * (cur_w_len + 1));
			word_cpy(str, w_list[w_found]);
			str += cur_w_len;
			w_found++;
		}
		str += 1;
	}
	w_list[w_quan] = NULL;
	return (w_list);
}
