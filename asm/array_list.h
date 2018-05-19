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

typedef struct	s_command
{
	char		type;
	char		codage_octal;
	char		*args[4];
	t_arg_type	arg_types[4];
}				t_command;

typedef struct	s_labeled_code
{
	char		*label;
	t_command	*command;
	int			bytecode_length;
	char		*bytecode;
}				t_labeled_code;

typedef struct	s_code_array_list
{
	int				size;
	int				capacity;
	t_labeled_code	**values;
}				t_code_array_list;

void			al_initialise(t_code_array_list *al, int initial_capacity);
void			al_insert(t_code_array_list *d, t_labeled_code *lc);
void			al_clear(t_code_array_list *d);

t_labeled_code	*al_get_by_index(t_code_array_list *d, int index);
t_labeled_code	*al_get_by_label(t_code_array_list *d, char *label);
void			al_map(t_code_array_list *self, void f(t_labeled_code *c));
int				al_index_of(t_code_array_list *self, char *label);
int				al_index_of_command(t_code_array_list *self, t_labeled_code *c);

#endif
