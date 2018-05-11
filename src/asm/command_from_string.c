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
		if (tokens[i][0] == DIRECT_CHAR)
			command->arg_types[i] = T_DIR;
		else if (tokens[i][0] == REG_CHAR)
			command->arg_types[i] = T_REG;
		else
			command->arg_types[i] = T_IND;
	}
}