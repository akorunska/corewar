/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:02:52 by ddenkin           #+#    #+#             */
/*   Updated: 2018/04/30 19:37:08 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "../../libft/libft.h"
# include "op.h"

typedef struct		s_field
{
	char			value;
	unsigned int	color;
	int				occupied;
}					t_field;

typedef struct		s_player
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				num;
}					t_player;

typedef	struct		s_proc
{
	struct s_proc	*next;
	char			reg[REG_NUMBER][REG_SIZE];
	int				index;
	int				carry;
	int				player;

}					t_proc;

typedef struct		s_core
{
	t_player		players[MAX_PLAYERS];
	t_field			f[MEM_SIZE];
	int				processes;
	int				total_players;
	int				total_cycles;
}					t_core;

void				move_proc(t_core *, t_proc *, int);

#endif
