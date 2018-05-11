/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:13:15 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/08 10:13:49 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_LIST_H
# define ARRAY_LIST_H

# include "op.h"

typedef struct s_command
{
	char		type;
	char		*args[3];
	t_arg_type 	arg_types[3];
}				t_command;

typedef struct	s_labeled_code
{
	char		*label;
	t_command	*command;
	int			bytecode_length;
}				t_labeled_code;

typedef struct	s_array_list
{
	int				size;
	int				capacity;
	t_labeled_code 	**values;
}				t_array_list;

#endif
