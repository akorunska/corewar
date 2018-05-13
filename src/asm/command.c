/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_from_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:36:17 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/11 18:36:19 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdlib.h>
#include "op.h"
#include "../libft/libft.h"
#include "array_list.h"

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
	free(tokens);
}

void		count_command_bytecode_length(t_labeled_code *c)
{
	int 	length;
	int 	i;

	length = 1;
	i = -1;
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

int 		label_to_int(t_labeled_code *cur, char *ref, t_array_list *al)
{
	int 	current_index;
	int 	referenced_index;
	int 	result;
	int 	dir;
	int 	i;

	current_index = al_index_of_command(al, cur);
	referenced_index = al_index_of(al, ref );
	printf("current: %i  referenced: %i\n", current_index, referenced_index);
	printf("refer label: %s\n", ref);
	dir = (current_index <= referenced_index) ? 1 : -1;
	result = 0;
	while (current_index != referenced_index)
	{
		result += al_get_by_index(al, current_index)->bytecode_length * dir;
		current_index += dir;
	}
	return (result);
}

void		convert_command_to_bytecode(t_labeled_code *c, t_array_list *al)
{
	int 	i;
	int 	len;
	int 	dir_value;
	char 	*res;

	res = (char *)malloc(sizeof(char) * c->bytecode_length);
	i = -1;
	len = 1;
	*res = c->command->type;
	while (c->command->args[++i]) {
		if (c->command->arg_types[i] == T_REG) {
			*((char *) (res + len)) = (char) ft_atoi(c->command->args[i] + 1);
			len += sizeof(char);
		} else if (c->command->arg_types[i] == T_IND)
		{
			*((short int *) (res + len)) = (short int) ft_atoi(c->command->args[i]);
			len += sizeof(short int);
		}
		else
		{
			dir_value = (c->command->arg_types[i] == T_LAB) ?
						label_to_int(c, c->command->args[i] + 2, al) :
						ft_atoi(c->command->args[i] + 1);
			printf("dir value is {%i}\n", dir_value);
			if (g_op_tab[c->command->type - 1].label_size == 0)
			{
				*((int *) (res + len)) = dir_value;
				len += sizeof(int);
			}
			else
			{
				*((short int *) (res + len)) = (short int) dir_value;
				len += sizeof(short int);
			}
		}
	}
	c->bytecode = res;
}
