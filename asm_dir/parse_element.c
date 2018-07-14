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

char	*search_endstring(char *arg, char **element)
{
	char	*last_entry;
	char	*temp;

	last_entry = ft_strchr(arg, '"');
	if (last_entry)
		*last_entry = '\0';
	temp = ft_strjoin(*element, "\n");
	free(*element);
	*element = temp;
	temp = ft_strjoin(*element, arg);
	free(*element);
	*element = temp;
	return (last_entry);
}

char	*parse_element(char **args, char *element_type)
{
	int		i;
	char	*first_entry;
	char	*last_entry;
	char	*element;

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
	element = ft_strsub(args[i - 1], (unsigned)(first_entry - args[i - 1]), \
		((last_entry) ? (last_entry - first_entry) : \
		(ft_strchr(args[i - 1], '\0') - first_entry)));
	i--;
	while (!last_entry)
		last_entry = search_endstring(args[++i], &element);
	return (element);
}
