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

void	get_meta(t_file *file, char **args)
{
	char	*temp;

	ft_bzero(file->header.prog_name, sizeof(char) * PROG_NAME_LENGTH);
	ft_bzero(file->header.comment, sizeof(char) * COMMENT_LENGTH);
	temp = parse_element(args, NAME_CMD_STRING);
	ft_strcpy(file->header.prog_name, temp);
	free(temp);
	temp = parse_element(args, COMMENT_CMD_STRING);
	ft_strcpy(file->header.comment, temp);
	free(temp);
}

int		get_bytecode(char **result, char **args)
{
	t_file		file;
	int			total_length;
	int			i;

	get_meta(&file, args);
	al_initialise(&(file.code), 4);
	i = -1;
	while (args[++i] != NULL)
		al_insert((&file.code), parse_command(args[i]));
	al_map(&file.code, count_command_bytecode_length);
	i = -1;
	while (++i < file.code.size)
	{
		if (!al_get_by_index(&file.code, i)->command)
			continue;
		convert_command_to_bytecode(al_get_by_index(&file.code, i), &file.code);
	}
	total_length = file_to_bytecode(&file);
	al_clear(&file.code);
	*result = file.result;
	return (total_length);
}
