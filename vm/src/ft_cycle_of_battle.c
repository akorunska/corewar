/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle_of_battle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:25:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/17 19:22:53 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_cycle_of_battle(t_mem *mem, t_info_players *info)
{
	mem->total_cycles++;
	mem->cur_cycles++;
	if (mem->cycle_to_die > 0)
		ft_one_cycle_processes(mem, info);
	if (mem->cur_cycles >= mem->cycle_to_die)
	{
		if (mem->verb[3] && !mem->visual)
			ft_verb_8(mem);
		if (mem->sum_alive < NBR_LIVE)
			mem->checks--;
		if (mem->sum_alive >= NBR_LIVE || !mem->checks)
		{
			mem->cycle_to_die -= CYCLE_DELTA;
			if (mem->verb[1] && !mem->visual)
				ft_printf("Cycle to die is now %d\n", mem->cycle_to_die);
			mem->checks = MAX_CHECKS;
		}
		ft_del_dead_processes(mem);
		ft_zero_alive(mem, info);
		mem->cur_cycles = 0;
	}
}

static void	play_kill(int num)
{
	int		n;

	if ((n = fork()) == 0)
	{
		if (num > 25)
		{
			if (access("sounds/gunshot2.mp3", F_OK) != -1)
				system("afplay sounds/gunshot2.mp3");
			if (access("sounds/scream2.mp3", F_OK) != -1)
				system("afplay sounds/scream2.mp3");
		}
		else
		{
			if (access("sounds/gunshot.mp3", F_OK) != -1)
				system("afplay sounds/gunshot.mp3");
			if (access("sounds/scream.mp3", F_OK) != -1)
				system("afplay sounds/scream.mp3");
		}
		exit(0);
	}
	return ;
}

void		ft_del_dead_processes(t_mem *mem)
{
	t_list_proc		*tmp_lst_proc;
	t_list_proc		*tmp_for_del;
	int				kill;

	tmp_lst_proc = mem->lst_proc;
	kill = 0;
	while (tmp_lst_proc)
	{
		if (!tmp_lst_proc->alive)
		{
			tmp_for_del = tmp_lst_proc;
			tmp_lst_proc = tmp_lst_proc->next;
			ft_lstprocdeloneany(&mem->lst_proc, &tmp_for_del);
			mem->lst_length--;
			++kill;
		}
		else
			tmp_lst_proc = tmp_lst_proc->next;
	}
	if (kill && mem->visual)
		play_kill(kill);
}

void		ft_zero_alive(t_mem *mem, t_info_players *info)
{
	t_list_proc		*tmp_lst_proc;
	int				i;

	tmp_lst_proc = mem->lst_proc;
	while (tmp_lst_proc)
	{
		tmp_lst_proc->alive = 0;
		tmp_lst_proc = tmp_lst_proc->next;
	}
	i = 0;
	while (i < MAX_PLAYERS)
		info->live[i++] = 0;
	mem->sum_alive = 0;
}
