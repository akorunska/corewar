/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_battle_without_nc.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:05:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/19 17:40:39 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_start_battle_without_nc(t_mem *mem, t_info_players *info)
{
	ft_output_head(info);
	while (1)
	{
		if (mem->lst_proc && mem->total_cycles != mem->nbr_cycles)
		{
			if (mem->verb[1])
				ft_printf("It is now cycle %d\n", mem->total_cycles + 1);
			ft_cycle_of_battle(mem, info);
		}
		else
			break ;
	}
	if (mem->lst_proc)
		ft_output_memory(mem);
	else
		ft_printf("Contestant %d, \"%s\", has won !\n", mem->id_winner,
					info->binary_players[mem->id_winner - 1].head->prog_name);
}
