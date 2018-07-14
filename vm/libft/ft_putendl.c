/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:11:26 by igaliuk           #+#    #+#             */
/*   Updated: 2017/10/30 14:11:28 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int	i;

	if (s != 0)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		write(1, s, i);
		write(1, "\n", 1);
	}
}
