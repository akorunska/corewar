/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_clean_join.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:51:44 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/05 13:51:45 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_clean_join(char **str1, char **str2)
{
	char	*res;
	char	*ret;
	int		i;

	if (!str1 || !str2)
		return (NULL);
	res = ft_strnew(ft_strlen(*str1) + ft_strlen(*str2));
	ret = res;
	i = 0;
	while (*(*str1 + i))
	{
		*res = *(*str1 + i);
		res++;
		i++;
	}
	ft_strdel(str1);
	i = 0;
	while (*(*str2 + i))
	{
		*res = *(*str2 + i);
		res++;
		i++;
	}
	ft_strdel(str2);
	return (ret);
}
