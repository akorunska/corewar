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

# include "array_list.h"
# include "libftprintf/libftprintf.h"

typedef struct			s_file
{
	t_header			header;
	t_code_array_list	code;
	char				*result;
}						t_file;

int						get_bytecode(char **result, char **args);

char					*parse_element(char **args, char *element_type);
t_labeled_code			*parse_command(char *line);

char					get_command_type(char *line);
void					get_arguments(t_command *command, char *line);
void					count_command_bytecode_length(t_labeled_code *c);
void					count_command_codage_octal(t_command *c);

void					convert_command_to_bytecode(t_labeled_code *c, \
						t_code_array_list *al);
int						write_data(char **dest, void *data, int len, char rev);

int						file_to_bytecode(t_file *file);

#endif
