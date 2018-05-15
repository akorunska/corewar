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
#include "../libft/libft.h"
#include "array_list.h"
#include "asm_parse.h"

char 		get_command_type(char *line)
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

void		get_arguments(t_command *command, char *line)
{
	char 	**tokens;
	char 	*temp;
	int		i;

	tokens = ft_strsplit(line, SEPARATOR_CHAR);
	i = -1;
	while (tokens[++i])
	{
		temp = ft_strtrim(tokens[i]);
		free(tokens[i]);
		tokens[i] = temp;
	}
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

void		count_command_bytecode_length(t_labeled_code *c)
{
	int 	length;
	int 	i;

	length = 1;
	i = -1;
	if (g_op_tab[c->command->type - 1].codage_octal)
		length++;
	while (c->command->args[++i])
	{
		if (c->command->arg_types[i] == T_REG)
			length +=1; 								// why 1, if typedefed reg_size is 4 ?
		else if (c->command->arg_types[i] == T_IND)
			length += IND_SIZE;
		else if (c->command->arg_types[i] == T_DIR || c->command->arg_types[i] == T_LAB)
			length += ((g_op_tab[c->command->type - 1].label_size == 0) ? DIR_SIZE : DIR_SIZE / 2);
	}
	c->bytecode_length = length;
}

void		count_command_codage_octal(t_command *c)
{
	char 	res;
	char 	value;
	int 	i;

	res = 0;
	i = -1;
	while (c->args[++i])
	{
		if (c->arg_types[i] == T_REG)
			value = REG_CODE;
		else if (c->arg_types[i] == T_DIR)
			value = DIR_CODE;
		else
			value = IND_CODE;
		res = (value << (6 - i * 2)) | res;
	}
	c->codage_octal = res;
}
