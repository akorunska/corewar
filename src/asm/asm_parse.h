/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:05:47 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/07 13:05:48 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ASM_PARSE_H
# define ASM_PARSE_H

# include "../libft/libft.h"
# include "op.h"
# include "array_list.h"

typedef struct	s_file
{
	header_t		header;
	t_array_list	code;
	char 			*result;
}				t_file;

char					*get_bytecode(char **args);

char					*parse_element(char **args, char *element_type);
t_labeled_code			*parse_command(char *line);

char 					get_command_type(char *line);
void					get_arguments(t_command *command, char *line);
void					count_command_bytecode_length(t_labeled_code *c);
void					count_command_codage_octal(t_command *c);

void					convert_command_to_bytecode(t_labeled_code *c, \
						t_array_list *al);
#endif