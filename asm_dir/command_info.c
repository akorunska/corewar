/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 21:04:11 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/15 21:04:16 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "op.h"
#include "../libftprintf/libftprintf.h"
#include "array_list.h"

char		**get_trimmed_tokens(char *line)
{
	char	**tokens;
	char	*temp;
	int		i;

	tokens = ft_strsplit(line, SEPARATOR_CHAR);
	i = -1;
	while (tokens[++i])
	{
		temp = ft_strtrim(tokens[i]);
		free(tokens[i]);
		tokens[i] = temp;
	}
	return (tokens);
}

void		count_command_bytecode_length(t_labeled_code *c)
{
	int		length;
	int		i;

	length = 1;
	i = -1;
	if (c->command == NULL)
	{
		c->bytecode = NULL;
		c->bytecode_length = 0;
		return ;
	}
	if (g_op_tab[c->command->type - 1].codage_octal)
		length++;
	while (c->command->args[++i])
	{
		if (c->command->arg_types[i] == T_REG)
			length += 1;
		else if (c->command->arg_types[i] == T_IND)
			length += IND_SIZE;
		else if (c->command->arg_types[i] == T_DIR || \
		c->command->arg_types[i] == T_LAB)
			length += ((g_op_tab[c->command->type - 1].label_size == 0) \
						? DIR_SIZE : DIR_SIZE / 2);
	}
	c->bytecode_length = length;
}

void		count_command_codage_octal(t_command *c)
{
	char	res;
	char	value;
	int		i;

	res = 0;
	i = -1;
	while (c->args[++i])
	{
		if (c->arg_types[i] == T_REG)
			value = REG_CODE;
		else if (c->arg_types[i] == T_DIR || c->arg_types[i] == T_LAB)
			value = DIR_CODE;
		else
			value = IND_CODE;
		res = (value << (6 - i * 2)) | res;
	}
	c->codage_octal = res;
}

void		get_arguments(t_command *command, char *line)
{
	char	**tokens;
	int		i;

	tokens = get_trimmed_tokens(line);
	i = -1;
	while (tokens[++i])
	{
		if (tokens[i][0] == DIRECT_CHAR && tokens[i][1] == LABEL_CHAR)
			command->arg_types[i] = T_LAB;
		else if (tokens[i][0] == DIRECT_CHAR)
			command->arg_types[i] = T_DIR;
		else if (tokens[i][0] == REG_CHAR)
			command->arg_types[i] = T_REG;
		else
			command->arg_types[i] = T_IND;
		command->args[i] = tokens[i];
	}
	command->args[i] = NULL;
	count_command_codage_octal(command);
	free(tokens);
}
