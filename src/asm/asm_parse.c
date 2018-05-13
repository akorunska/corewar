/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:41:53 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/07 12:42:01 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include <stdlib.h>
#include <stdio.h> //
#include "array_list.h"
/* assuming everything in given args is valid */

void	convert_to_bytecode(t_file *file) {
//	file->header.magic = COREWAR_EXEC_MAGIC;
	for (int i = 0; i < file->code.size; i++)
	{
		printf("bytecode len is {%i}\n", file->code.values[i]->bytecode_length);
		for (int j = 0; j < file->code.values[i]->bytecode_length; j++)
		{
			printf("%.2x ", (char)file->code.values[i]->bytecode[j]);
		}
		printf("\n");
	}
}

void	print_file(char **args) //
{
	int		i;

	i = 0;
	while (args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}
}

void	get_meta(t_file *file, char **args)
{
	char	*temp;

	temp = parse_element(args, NAME_CMD_STRING);
	ft_strcpy(file->header.prog_name, temp);
	free(temp);
	temp = parse_element(args, COMMENT_CMD_STRING);
	ft_strcpy(file->header.comment, temp);
	free(temp);
}

char	*get_bytecode(char **args)
{
	t_file		file;
	char 		*temp;
	int			i;

//	print_file(args);	// debug
	get_meta(&file, args);

	// todo find first line where code starts
	al_initialise(&(file.code), 4);
	i = -1;
	while (args[++i] != NULL)
		al_insert((&file.code), parse_command(args[i]));
	al_map(&file.code, count_command_bytecode_length);
	i = -1;
	while (++i < file.code.size)
		convert_command_to_bytecode(al_get_by_index(&file.code, i), &file.code);
	convert_to_bytecode(&file);
	return (file.result);
}
