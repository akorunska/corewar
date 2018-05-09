/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 20:57:06 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/27 10:15:02 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int	j;

	j = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[j] == (unsigned char)s2[j] && \
			s1[j] != '\0' && s2[j] != '\0' && j < n)
	{
		j++;
	}
	if (j == n)
		return ((unsigned char)s1[j - 1] - (unsigned char)s2[j - 1]);
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
