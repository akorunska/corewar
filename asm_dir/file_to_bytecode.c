/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_bytecode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:00:34 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/16 12:00:35 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm_parse.h"

void	count_code_length(t_file *file)
{
	int				i;
	t_labeled_code	*cur;

	i = -1;
	file->header.prog_size = 0;
	while (++i < file->code.size)
	{
		cur = al_get_by_index(&file->code, i);
		if (cur->command != NULL)
			file->header.prog_size += cur->bytecode_length;
	}
}

int		count_total_length(t_file *file)
{
	int		res;

	count_code_length(file);
	res = 4;
	res += PROG_NAME_LENGTH;
	res += 4;
	res += 4;
	res += COMMENT_LENGTH;
	res += 4;
	res += file->header.prog_size;
	return (res);
}

int		file_to_bytecode(t_file *file)
{
	char			*res;
	t_labeled_code	*cur;
	int				total_lenth;
	int				zero;
	int				i;

	zero = 0;
	total_lenth = count_total_length(file);
	res = (char *)malloc(sizeof(char) * total_lenth);
	file->result = res;
	file->header.magic = COREWAR_EXEC_MAGIC;
	res += write_data(&res, &file->header.magic, 4, 1);
	res += write_data(&res, &file->header.prog_name, PROG_NAME_LENGTH, 0);
	res += write_data(&res, &zero, 4, 0);
	res += write_data(&res, &file->header.prog_size, 4, 1);
	res += write_data(&res, &file->header.comment, COMMENT_LENGTH, 0);
	res += write_data(&res, &zero, 4, 0);
	i = -1;
	while (++i < file->code.size)
	{
		cur = al_get_by_index(&file->code, i);
		if (cur->command)
			res += write_data(&res, cur->bytecode, cur->bytecode_length, 0);
	}
	return (total_lenth);
}
