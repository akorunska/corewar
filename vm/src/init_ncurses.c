/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:37:08 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/19 18:13:19 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		init_ncurses(void)
{
	if (!initscr())
		return (-1);
	if (!has_colors())
		return (-2);
	noecho();
	start_color();
	nodelay(stdscr, TRUE);
	set_escdelay(25);
	keypad(stdscr, TRUE);
	init_color(COLOR_WHITE, 500, 500, 500);
	init_pair(0, COLOR_CYAN, COLOR_BLACK);
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_GREEN, COLOR_WHITE);
	init_pair(8, COLOR_BLUE, COLOR_WHITE);
	init_pair(9, COLOR_RED, COLOR_WHITE);
	init_pair(10, COLOR_CYAN, COLOR_WHITE);
	init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(12, COLOR_WHITE, COLOR_BLACK);
	curs_set(FALSE);
	return (0);
}

void	winner(t_mem *mem, t_info_players *info)
{
	attron(A_BOLD);
	move(25 + info->num_pl * 4, 199);
	printw("The winner is : ");
	attron(COLOR_PAIR(mem->id_winner + 1));
	printw("%.37s", info->binary_players[mem->id_winner - 1].head->prog_name);
	attroff(666);
	move(27 + info->num_pl * 4, 199);
	printw("Press any key to finish");
	refresh();
	nodelay(stdscr, FALSE);
	getch();
}

void	proper_init(t_mem *mem, t_info_players *info)
{
	int		key;

	if ((key = init_ncurses()) == -1)
		return (ft_error_init_nc(mem, info));
	else if (key == -2)
		return (ft_error_colors_nc(mem, info));
}
