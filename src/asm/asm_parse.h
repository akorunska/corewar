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

#endif