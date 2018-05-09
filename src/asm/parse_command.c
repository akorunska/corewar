/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:03:08 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/08 15:03:10 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"
#include "../libft/libft.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h> // debugging

char 				*find_label(char *line)
{
	char 	*label_char_position;
	size_t 	label_char_index;
	char	*label;

	label_char_position = ft_strchr(line, LABEL_CHAR);
	if (!label_char_position || label_char_position == line)
		return ft_strnew(1);
	label_char_index = (--label_char_position) - line;
	while (label_char_position != line)
	{
		if (!strchr(LABEL_CHARS, *label_char_position))
			return ft_strnew(1);
		label_char_position--;
	}
	label = ft_strsub(line, 0, label_char_index + 1);
	return (label);
}

t_labeled_code		*parse_command(char *line)
{
	t_labeled_code	*parsed_command;

	// todo return NULL if line is empty
	parsed_command = (t_labeled_code *)malloc(sizeof(t_labeled_code));
	parsed_command->label = find_label(line);
	printf("line {%s} || found label {%s}\n", line, parsed_command->label);
	return (NULL);
}
