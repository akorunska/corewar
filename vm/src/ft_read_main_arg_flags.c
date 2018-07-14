/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_main_arg_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:55:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/07 18:07:13 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_read_flags_vis_aff_dump(t_mem *mem, int *argc, char ***argv)
{
	if (!ft_strcmp(**argv, "-vis"))
		mem->visual = 1;
	else if (!ft_strcmp(**argv, "-aff"))
		mem->aff = 1;
	else
	{
		if (*argc > 2)
		{
			mem->nbr_cycles = ft_atoi_vm(*++*argv);
			(*argc)--;
		}
		else
			ft_usage_vm();
	}
}

void	ft_read_flag_verb(t_mem *mem, int *argc, char ***argv)
{
	int		value;
	int		i;

	if (*argc > 2 && (value = ft_atoi_vm(*++*argv)) > 0 && value < 32)
	{
		i = 0;
		while (i < 5)
		{
			if ((value & (1 << i)) > 0)
				mem->verb[i] = 1;
			i++;
		}
		(*argc)--;
	}
	else
		ft_usage_vm();
}

int		ft_read_flag_n(t_info_players *info, int *argc, char ***argv)
{
	int		order;

	order = 0;
	if (*argc > 3 && *(*argv + 2)[0] != '-')
	{
		order = ft_atoi_vm(*++*argv);
		(*argc)--;
	}
	else
		ft_usage_vm();
	if (order < 1 || order > 4 ||
		ft_check_doubles_order(info, order))
		ft_usage_vm();
	return (order);
}

int		ft_check_doubles_order(t_info_players *info, int order)
{
	int		pl;

	pl = 0;
	while (pl < info->num_pl)
	{
		if (info->order_players[pl] == order)
			return (-1);
		pl++;
	}
	return (0);
}
