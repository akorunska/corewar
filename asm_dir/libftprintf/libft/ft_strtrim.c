/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:44:51 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/07 18:20:30 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	white_s;
	unsigned int	white_e;
	char			*cpy;

	if (!s)
		return (NULL);
	white_s = 0;
	while (s[white_s] && ft_isspace(s[white_s]))
		white_s++;
	if (s[white_s] == '\0')
		return (ft_strnew(0));
	cpy = (char*)s + ft_strlen(s) - 1;
	white_e = 0;
	while (cpy > s && ft_isspace(*cpy))
	{
		white_e++;
		cpy--;
	}
	return (ft_strsub(s, white_s, ft_strlen(s) - white_s - white_e));
}
