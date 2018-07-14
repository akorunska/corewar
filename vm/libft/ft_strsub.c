/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:17:59 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/01 17:18:02 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	if (s != NULL)
	{
		tmp = ft_strnew(len);
		if (tmp == NULL)
			return (NULL);
		return (ft_strncpy(tmp, s + start, len));
	}
	return (NULL);
}
