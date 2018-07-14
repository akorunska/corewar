/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees_vm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:12:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/07 18:07:13 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_frees_vm(t_mem *mem, t_info_players *info)
{
	if (mem)
		ft_frees_mem(mem);
	if (info)
		ft_frees_info(info);
}

void	ft_frees_mem(t_mem *mem)
{
	if (mem->str_mem)
		ft_strdel(&mem->str_mem);
	if (mem->str_mem_pl)
		ft_strdel(&mem->str_mem_pl);
	if (mem->str_mem_bold)
		ft_strdel(&mem->str_mem_bold);
	if (mem->str_mem_inv)
		ft_strdel(&mem->str_mem_inv);
	if (mem->str_mem_live)
		ft_strdel(&mem->str_mem_live);
	if (mem->lst_proc)
		ft_lstprocdel(&mem->lst_proc);
}

void	ft_frees_info(t_info_players *info)
{
	while (info->num_pl > 0)
	{
		if (info->binary_players[info->num_pl - 1].head)
		{
			free(info->binary_players[info->num_pl - 1].head);
			info->binary_players[info->num_pl - 1].head = NULL;
		}
		if (info->binary_players[info->num_pl - 1].prog)
		{
			free(info->binary_players[info->num_pl - 1].prog);
			info->binary_players[info->num_pl - 1].prog = NULL;
		}
		info->num_pl--;
	}
}
