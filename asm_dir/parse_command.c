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
#include "../libftprintf/libftprintf.h"
#include "asm_parse.h"
#include <stdlib.h>

char				*find_label(char *line)
{
	char	*label_char_position;
	size_t	label_char_index;
	char	*label;

	label_char_position = ft_strchr(line, LABEL_CHAR);
	if (!label_char_position || label_char_position == line)
		return (ft_strnew(1));
	label_char_index = (--label_char_position) - line;
	while (label_char_position != line)
	{
		if (!strchr(LABEL_CHARS, *label_char_position))
			return (ft_strnew(1));
		label_char_position--;
	}
	label = ft_strsub(line, 0, label_char_index + 1);
	return (label);
}

char				*get_trimmed_command(char *line)
{
	char	*res;
	char	*comment_pos2;
	char	*comment_pos1;
	char	*comment_start;
	int		start_position;

	comment_pos1 = ft_strchr(line, COMMENT_CHAR);
	comment_pos2 = ft_strchr(line, COMMENT_CHAR_ADD);
	if (comment_pos1 && comment_pos2)
		comment_start = (((comment_pos1 - comment_pos2) > 0)
							? comment_pos2 : comment_pos1);
	else if (comment_pos1)
		comment_start = comment_pos1;
	else if (comment_pos2)
		comment_start = comment_pos2;
	else
		comment_start = NULL;
	start_position = 0;
	while (line[start_position] == ' ' || line[start_position] == '\t')
		start_position++;
	res = ft_strsub(line, (unsigned int)start_position,
	(comment_start ? comment_start - line : ft_strlen(line)) - start_position);
	return (res);
}

char				get_command_type(char *line)
{
	int		i;

	i = 16;
	while (--i >= 0)
	{
		if (!ft_strncmp(line, g_op_tab[i].name, ft_strlen(g_op_tab[i].name)))
			return ((char)(i + 1));
	}
	return (0);
}

t_labeled_code		*parse_command(char *line)
{
	t_labeled_code			*parsed_command;
	char					*trimmed_command;
	int						command_start;

	parsed_command = (t_labeled_code *)malloc(sizeof(t_labeled_code));
	parsed_command->label = find_label(line);
	command_start = (int)(!ft_strcmp("", parsed_command->label)
							? 0 : ft_strlen(parsed_command->label) + 1);
	trimmed_command = get_trimmed_command(line + command_start);
	parsed_command->command = (t_command *)malloc(sizeof(t_command));
	parsed_command->command->type = get_command_type(trimmed_command);
	if (parsed_command->command->type)
		get_arguments(parsed_command->command, trimmed_command + \
		ft_strlen(g_op_tab[parsed_command->command->type - 1].name));
	else
	{
		ft_memdel((void**)&(parsed_command->command));
		if (!ft_strcmp("", parsed_command->label))
		{
			ft_memdel((void**)&(parsed_command->label));
			ft_memdel((void**)&parsed_command);
		}
	}
	free(trimmed_command);
	return (parsed_command);
}
