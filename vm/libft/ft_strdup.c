/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:42:33 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/10 11:12:03 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mlc;

	mlc = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (mlc == NULL)
		return (NULL);
	return (ft_strcpy(mlc, s1));
}
