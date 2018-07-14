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
#include "../libftprintf/libftprintf.h"
#include "array_list.h"

int			label_to_int(t_labeled_code *cur, char *ref, t_code_array_list *al)
{
	int		current_index;
	int		referenced_index;
	int		result;
	int		dir;

	current_index = al_index_of_command(al, cur);
	referenced_index = al_index_of(al, ref);
	dir = (current_index <= referenced_index) ? 1 : -1;
	if (dir < 0)
	{
		current_index--;
		referenced_index--;
	}
	result = 0;
	while (current_index != referenced_index)
	{
		result += al_get_by_index(al, current_index)->bytecode_length * dir;
		current_index += dir;
	}
	return (result);
}

int			write_data(char **dest, void *data, int len, char rev)
{
	char	*src;
	char	temp;
	int		i;
	int		j;

	src = (char *)data;
	j = -1;
	while (++j < len)
		(*dest)[j] = src[j];
	j--;
	if (rev)
	{
		i = 0;
		while (i < j)
		{
			temp = (*dest)[i];
			(*dest)[i] = (*dest)[j];
			(*dest)[j] = temp;
			i++;
			j--;
		}
	}
	return (len);
}

int			write_argument(char *res, t_code_array_list *al, \
										t_labeled_code *c, int i)
{
	int		value;
	int		shift;

	if (c->command->arg_types[i] == T_REG)
	{
		value = ft_atoi(c->command->args[i] + 1);
		shift = write_data(&res, &value, 1, 0);
	}
	else if (c->command->arg_types[i] == T_IND)
	{
		value = ((c->command->args[i][0] == LABEL_CHAR) ? label_to_int(c, \
			c->command->args[i] + 1, al) : ft_atoi(c->command->args[i]));
		shift = write_data(&res, &value, IND_SIZE, 1);
	}
	else
	{
		value = (c->command->arg_types[i] == T_LAB) ?
				label_to_int(c, c->command->args[i] + 2, al) :
				ft_atoi(c->command->args[i] + 1);
		shift = write_data(&res, &value, \
			(g_op_tab[c->command->type - 1].label_size == 0 ?
			DIR_SIZE : DIR_SIZE / 2), 1);
	}
	return (shift);
}

void		convert_command_to_bytecode(t_labeled_code *c,\
											t_code_array_list *al)
{
	int		i;
	char	*res;

	res = (char *)malloc(sizeof(char) * c->bytecode_length);
	c->bytecode = res;
	i = -1;
	res += write_data(&res, &(c->command->type), 1, 0);
	if (g_op_tab[c->command->type - 1].codage_octal)
		res += write_data(&res, &(c->command->codage_octal), 1, 0);
	while (c->command->args[++i] != NULL)
		res += write_argument(res, al, c, i);
}
