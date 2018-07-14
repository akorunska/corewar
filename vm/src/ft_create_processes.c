/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_processes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:05:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/11 17:08:11 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_create_processes_new_list(t_mem *mem, t_info_players *info,
	int pl)
{
	t_list_proc	*tmp_lst_proc;

	if (!(tmp_lst_proc = ft_lstprocnew(pl * MEM_SIZE / info->num_pl,
		(char)(pl + 1))))
		ft_error_malloc(mem, info);
	mem->lst_length++;
	tmp_lst_proc->reg[0] -= (char)(pl + 1);
	ft_lstprocadd(&mem->lst_proc, tmp_lst_proc);
}

void		ft_create_processes(t_mem *mem, t_info_players *info)
{
	int			order;
	char		pl;

	ft_order_processes(info);
	order = 4;
	while (order >= 1)
	{
		pl = 0;
		while (pl < MAX_PLAYERS)
		{
			if (info->order_players[(int)pl] == order)
			{
				ft_create_processes_new_list(mem, info, pl);
				if (mem->visual)
					mem->str_mem_inv[pl * MEM_SIZE / info->num_pl] = 1;
				break ;
			}
			pl++;
		}
		order--;
	}
}

void		ft_order_processes(t_info_players *info)
{
	int		cur_num;
	int		i;

	cur_num = 1;
	while (cur_num <= 4)
	{
		if (!ft_check_have_this_order(info, cur_num))
		{
			i = info->num_pl - 1;
			while (i >= 0)
			{
				if (!info->order_players[i])
				{
					info->order_players[i] = cur_num;
					break ;
				}
				i--;
			}
		}
		cur_num++;
	}
}

int			ft_check_have_this_order(t_info_players *info, int cur_num)
{
	int		i;

	i = 0;
	while (i < info->num_pl)
	{
		if (info->order_players[i] == cur_num)
			return (1);
		i++;
	}
	return (0);
}
