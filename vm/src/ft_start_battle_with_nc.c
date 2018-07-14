/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_battle_with_nc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 09:26:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/23 17:07:11 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	draw_border(void)
{
	int i;

	attron(COLOR_PAIR(6));
	printw("%0255d", 0);
	i = 0;
	while (++i <= 67)
	{
		move(i, 0);
		printw("*");
	}
	printw("%0255d", 0);
	while (--i >= 0)
	{
		move(i, 196);
		printw("*");
	}
	while (++i <= 67)
	{
		move(i, 255);
		printw("*");
	}
	attroff(COLOR_PAIR(666));
}

static void	print_stats(t_mem *mem, t_info_players *info)
{
	int i;

	attron(A_BOLD);
	move(2, 199);
	printw(mem->paused == 1 ? "** PAUSED **" : "** RUNNING **");
	move(4, 199);
	printw("Cycles/second limit : %-5d", mem->limit);
	move(7, 199);
	printw("Cycle : %-10d", mem->total_cycles);
	move(9, 199);
	printw("Processes : %-5d", mem->lst_length);
	i = -1;
	while (++i < info->num_pl)
		print_pl_info(info, i);
	print_breakdown(mem, info);
	move(17 + info->num_pl * 4, 199);
	printw("CYCLE_TO_DIE : %-10d", mem->cycle_to_die);
	move(19 + info->num_pl * 4, 199);
	printw("CYCLE_DELTA : %-10d", CYCLE_DELTA);
	move(21 + info->num_pl * 4, 199);
	printw("NBR_LIVE : %-10d", NBR_LIVE);
	move(23 + info->num_pl * 4, 199);
	printw("MAX_CHECKS : %-10d", MAX_CHECKS);
	attroff(A_BOLD);
}

static void	ft_print_one_byte_memory(t_mem *mem, int i)
{
	if (mem->str_mem_live[i] > 0)
		attron(COLOR_PAIR(6 + mem->str_mem_pl[i]));
	else if (mem->str_mem_pl[i] > 0)
		attron(COLOR_PAIR(1 + mem->str_mem_pl[i]));
	else if (mem->str_mem_inv[i])
		attron(COLOR_PAIR(6));
	else
		attron(COLOR_PAIR(1));
	if ((mem->str_mem_bold[i] || (mem->str_mem_pl[i] == 0 &&
			!mem->str_mem_inv[i])) || mem->str_mem_live[i])
		attron(A_BOLD);
	(mem->str_mem_inv[i]) ? attron(A_REVERSE) : 0;
	printw("%02x", (unsigned char)mem->str_mem[i]);
	(mem->str_mem_inv[i]) ? attroff(A_REVERSE) : 0;
	attroff(COLOR_PAIR(666));
	if ((mem->str_mem_bold[i] || (mem->str_mem_pl[i]
						== 0 && !mem->str_mem_inv[i])) || mem->str_mem_live[i])
		attroff(A_BOLD);
	if (mem->str_mem_live[i] && mem->paused == 0)
		mem->str_mem_live[i]--;
	if (mem->str_mem_bold[i] && mem->paused == 0)
		mem->str_mem_bold[i]--;
	if (mem->str_mem_inv[i] && mem->paused == 0)
		mem->str_mem_inv[i]--;
}

static void	print_mem(t_mem *mem, t_info_players *info)
{
	int i;

	i = 0;
	erase();
	draw_border();
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			move(2 + i / 64, 3);
		ft_print_one_byte_memory(mem, i);
		printw(" ");
		i++;
	}
	print_stats(mem, info);
	refresh();
}

void		ft_start_battle_with_nc(t_mem *mem, t_info_players *info)
{
	int				key;
	struct timeval	te;
	long long		mstart;
	long long		mend;

	mem->paused = 1;
	proper_init(mem, info);
	while (1)
	{
		gettimeofday(&te, NULL);
		mstart = te.tv_sec * 1000LL + te.tv_usec / 1000;
		if (mem->lst_proc && mem->cycle_to_die > 0 && mem->total_cycles !=
											mem->nbr_cycles && mem->paused == 0)
			ft_cycle_of_battle(mem, info);
		((key = getch()) == 'p') ? mem->paused ^= 1 : 0;
		(key == KEY_RIGHT) ? mem->limit = ft_min(1000, mem->limit + 5) : 0;
		(key == KEY_LEFT) ? mem->limit = ft_max(5, mem->limit - 5) : 0;
		print_mem(mem, info);
		if (key == 'q' || !mem->lst_proc || mem->cycle_to_die <= 0)
			break ;
		mend = te.tv_sec * 1000LL + te.tv_usec / 1000;
		(mem->paused == 0) ? usleep(1000000 / mem->limit - (mend - mstart)) : 0;
	}
	(key != 'q') ? winner(mem, info) : 0;
	endwin();
}
