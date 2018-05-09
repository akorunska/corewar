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

/* assuming everything in given args is valid */

void	convert_to_bytecode(t_file *file) {
	file->header.magic = COREWAR_EXEC_MAGIC;
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

char	*get_bytecode(char **args)
{
	t_file		file;
	char 		*temp;
	int			i;

//	print_file(args);	// debug
	temp = parse_element(args, NAME_CMD_STRING);
	ft_strcpy(file.header.prog_name, temp);
	free(temp);
	temp = parse_element(args, COMMENT_CMD_STRING);
	ft_strcpy(file.header.comment, temp);
	free(temp);
	printf("name: {%s}\n comment: {%s}\n", file.header.prog_name, file.header.comment);

	// todo find first line where code starts

	i = -1;
	while (args[++i] != NULL)
		parse_command(args[i]);

	convert_to_bytecode(&file);
	return (file.result);
}
