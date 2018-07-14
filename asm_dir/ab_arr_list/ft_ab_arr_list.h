/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ab_arr_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:16:54 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/09 20:16:55 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AB_ARR_LIST_H
# define FT_AB_ARR_LIST_H

# include "../libftprintf/libftprintf.h"

typedef struct		s_array_list
{
	int				capacity;
	int				size;
	size_t			elem_size;
	void			**data;
}					t_array_list;

t_array_list		*ft_al_init(int init_capacity, size_t elem_size);
void				ft_al_stretch(t_array_list *al);
void				ft_al_insert(t_array_list *al, void *elem);
void				ft_al_clear(t_array_list *al);

#endif
