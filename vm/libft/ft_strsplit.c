/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:17:36 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/01 17:17:38 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsplitwords(char const *s, char c, int w, int *start)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (((s[0] != c) && (i == 0)) || ((s[i] == c)
			&& (s[i + 1] != c) && (s[i + 1] != '\0')))
			w++;
		if ((s[i] != c) && (*start == -1))
			*start = i;
		i++;
	}
	return (w);
}

static void	*ft_strsplitcpy(char const *s, char c, char **tmp, int *start)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	while (j < ft_strsplitwords(s, c, 0, start))
	{
		i = *start;
		while (s[i] != c)
			i++;
		tmp[j] = (char*)malloc(sizeof(char) * (i - *start + 1));
		if (tmp[j] == 0)
			return (0);
		tmp[j][i - *start] = '\0';
		k = 0;
		i = *start;
		while ((s[i] != c) && (s[i] != '\0'))
			tmp[j][k++] = s[(i)++];
		j++;
		while (s[i] == c)
			i++;
		*start = i;
	}
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	int		w;
	int		start;

	if (s != 0)
	{
		start = -1;
		w = ft_strsplitwords(s, c, 0, &start);
		tmp = (char**)malloc(sizeof(char*) * (w + 1));
		if (tmp == 0)
			return (0);
		tmp[w] = 0;
		start = -1;
		w = 0;
		ft_strsplitcpy(s, c, tmp, &start);
		return (tmp);
	}
	return (0);
}
