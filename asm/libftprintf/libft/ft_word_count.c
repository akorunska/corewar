/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:30:38 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/12 21:30:50 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_word_count(char const *str, char delim)
{
	int		i;
	int		size;
	int		counter;
	int		flag;

	if (str == NULL)
		return (-1);
	i = 0;
	flag = 0;
	counter = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		if (str[i] == delim)
			flag = 0;
		else if (str[i] != delim && flag == 0)
		{
			flag = 1;
			counter++;
		}
		i++;
	}
	return (counter);
}
