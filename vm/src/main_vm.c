/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:07:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/17 19:25:54 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_init_mem(t_mem *mem)
{
	int		i;

	if (!(mem->str_mem = ft_strnew(MEM_SIZE))
		|| !(mem->str_mem_pl = ft_strnew(MEM_SIZE))
		|| !(mem->str_mem_bold = ft_strnew(MEM_SIZE))
		|| !(mem->str_mem_inv = ft_strnew(MEM_SIZE))
		|| !(mem->str_mem_live = ft_strnew(MEM_SIZE)))
		ft_error_malloc(mem, NULL);
	mem->lst_proc = NULL;
	mem->lst_length = 0;
	mem->num_pl = 0;
	mem->id_winner = 0;
	mem->total_cycles = 0;
	mem->nbr_cycles = -1;
	mem->cur_cycles = 0;
	mem->cycle_to_die = CYCLE_TO_DIE;
	mem->checks = MAX_CHECKS;
	mem->sum_alive = 0;
	mem->limit = 50;
	i = 0;
	while (i < 5)
		mem->verb[i++] = 0;
	mem->visual = 0;
	mem->aff = 0;
}

static void	ft_init_info(t_info_players *info)
{
	int		i;

	info->num_pl = 0;
	i = 0;
	while (i < MAX_PLAYERS)
	{
		info->live[i] = 0;
		info->last_live[i] = 0;
		info->binary_players[i].head = NULL;
		info->binary_players[i].prog = NULL;
		info->order_players[i++] = 0;
	}
}

int			main(int argc, char **argv)
{
	t_mem			mem;
	t_info_players	info;

	ft_init_mem(&mem);
	ft_init_info(&info);
	ft_read_main_arg(&mem, &info, argc, argv);
	ft_read_players(&mem, &info);
	ft_create_processes(&mem, &info);
	if (mem.visual)
		ft_start_battle_with_nc(&mem, &info);
	else
		ft_start_battle_without_nc(&mem, &info);
	ft_frees_vm(&mem, &info);
	return (0);
}
