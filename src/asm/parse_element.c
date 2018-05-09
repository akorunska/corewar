/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:22:21 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/08 14:22:23 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include <stdlib.h>

char	*parse_element(char **args, char *element_type) {
	int		i;
	char 	*first_entry;
	char 	*last_entry;
	char 	*element;
	char	*temp;

	i = 0;
	first_entry = NULL;
	last_entry = NULL;
	while (!first_entry)
	{
		if (!ft_strncmp(args[i], element_type, ft_strlen(element_type)))
		{
			first_entry = ft_strchr(args[i], '"') + 1;
			last_entry = ft_strchr(first_entry, '"');
		}
		i++;
	}
	element = ft_strsub(args[i - 1], (unsigned int)(first_entry - args[i - 1]), ((last_entry)
	? (last_entry - first_entry) : (ft_strchr(args[i - 1], '\0') - first_entry)));
	while (!last_entry)
	{
		last_entry = ft_strchr(args[i], '"');
		if (last_entry)
			*last_entry = '\0';
		temp = ft_strjoin(element, "\n");
		free(element);
		element = temp;
		temp = ft_strjoin(element, args[i]);
		free(element);
		element = temp;
		i++;
	}
	return (element);
}