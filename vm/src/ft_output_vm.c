/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:46:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/12 20:21:43 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_output_head(t_info_players *info)
{
	int		pl;

	ft_printf("Introducing contestants...\n");
	pl = 0;
	while (pl < info->num_pl)
	{
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
				pl + 1, info->binary_players[pl].head->prog_size,
				info->binary_players[pl].head->prog_name,
				info->binary_players[pl].head->comment);
		pl++;
	}
}

void	ft_output_memory(t_mem *mem)
{
	int		i;
	int		j;

	j = 0;
	while (j < 64)
	{
		ft_printf("0x%.4x : ", j * 64);
		i = 0;
		while (i < 64)
		{
			ft_printf("%.2x ", (unsigned char)mem->str_mem[i + j * 64]);
			if (!((i + 1) % 64))
				ft_printf("\n");
			i++;
		}
		j++;
	}
}
