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
#include "asm_parse.h"
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

char 				*get_trimmed_command(char *line)
{
	char 	*res;
	char 	*comment_pos2;
	char 	*comment_pos1;
	char 	*comment_start;
	int 	start_position;

	comment_pos1 = ft_strchr(line, COMMENT_CHAR);
	comment_pos2 = ft_strchr(line, COMMENT_CHAR_ADD);
	if (comment_pos1 && comment_pos2)
		comment_start = (((comment_pos1 - comment_pos2) > 0) ? comment_pos2 : comment_pos1);
	else if (comment_pos1)
		comment_start = comment_pos1;
	else if (comment_pos2)
		comment_start = comment_pos2;
	else
		comment_start = NULL;
	start_position = 0;
	while (line[start_position] == ' ' || line[start_position] == '\t')
		start_position++;
	res = ft_strsub(line, start_position,(comment_start ? comment_start - line : ft_strlen(line)) - start_position);
	return (res);
}

t_labeled_code		*parse_command(char *line) {
	static char 			*label;
	static char 			leftover;
	t_labeled_code 			*parsed_command;
	char 					*trimmed_command;
	int 					command_start;

	// todo return NULL if line is empty
	parsed_command = (t_labeled_code *)malloc(sizeof(t_labeled_code));
	if (!label)
		label = find_label(line);
	command_start = (int)(!ft_strcmp("", label) || leftover
					 ? 0 : ft_strlen(label) + 1);
	trimmed_command = get_trimmed_command(line + command_start);
	parsed_command->command = (t_command *)malloc(sizeof(t_command));
	parsed_command->command->type = get_command_type(trimmed_command);
	printf("{%s}\n", trimmed_command);
	if (parsed_command->command->type)
	{
//		printf("{%s} {%i}\n", trimmed_command, parsed_command->command->type);
		parsed_command->label = label;
		get_arguments(parsed_command->command, trimmed_command + ft_strlen(g_op_tab[parsed_command->command->type - 1].name));
		label = NULL;
		leftover = 0;
	}
	else
	{
//		printf("lbl: {%s}\n", label);
		if (!ft_strcmp("", label))
		{
			free(label);
			label = NULL;
			leftover = 0;
		}
		leftover = 1;
		free(parsed_command->command);
		free(parsed_command);
		parsed_command = NULL;
	}
	return (parsed_command);
}
