/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 21:33:17 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/10 21:38:28 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_pl_info(t_info_players *info, int num)
{
	move(11 + num * 4, 199);
	printw("Player %1d : ", num + 1);
	attron(COLOR_PAIR(2 + num));
	printw("%-.41s", info->binary_players[num].head->prog_name);
	attroff(666);
	move(12 + num * 4, 201);
	printw("Last live : %22d", info->last_live[num]);
	move(13 + num * 4, 201);
	printw("Lives in current period : %8d", info->live[num]);
	attroff(COLOR_PAIR(666));
}

int		ft_sum(const int *arr, int size)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (i < size)
	{
		res += arr[i];
		i++;
	}
	return (res);
}

void	small_pl_stat(t_info_players *info, int count[MAX_PLAYERS],
												int arr[MAX_PLAYERS])
{
	int i;
	int sum;

	i = -1;
	if ((sum = ft_sum(arr, info->num_pl)) != 0)
	{
		while (++i < info->num_pl)
		{
			count[i] = 50 * arr[i] / sum;
			attron(COLOR_PAIR(2 + i));
			if (i == info->num_pl - 1)
				(count[i] > 0) ? attron(COLOR_PAIR(2 + i)) : attroff(666);
			printw("%.*s", (i != info->num_pl - 1) ? count[i] : 50 -
					ft_sum(count, info->num_pl - 1), MINUSES);
		}
		attroff(666);
	}
	else
	{
		attroff(A_BOLD);
		printw(MINUSES);
		attron(A_BOLD);
	}
}

void	print_perc(int arr[MAX_PLAYERS], t_info_players *info, t_mem *mem,
														int save[MAX_PLAYERS])
{
	int			count[MAX_PLAYERS];
	static int	old[MAX_PLAYERS];

	printw("[");
	small_pl_stat(info, count, arr);
	printw("]");
	if (arr != save)
	{
		if (mem->cur_cycles == 0)
			ft_memcpy(save, old, sizeof(int) * info->num_pl);
		else
			ft_memcpy(old, arr, sizeof(int) * info->num_pl);
	}
}

void	print_breakdown(t_mem *mem, t_info_players *info)
{
	static int count[MAX_PLAYERS];

	move(11 + info->num_pl * 4, 199);
	printw("Live breakdown for current period :");
	move(12 + info->num_pl * 4, 199);
	print_perc(info->live, info, mem, count);
	move(14 + info->num_pl * 4, 199);
	printw("Live breakdown for last period :");
	move(15 + info->num_pl * 4, 199);
	print_perc(count, info, mem, count);
}
