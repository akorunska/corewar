/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_main_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:55:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/07 18:07:13 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_read_main_arg(t_mem *mem, t_info_players *info, int argc,
							char **argv)
{
	int		order;

	if (argc == 1)
		ft_usage_vm();
	order = 0;
	argv++;
	while (argc > 1)
	{
		if (!ft_strcmp(*argv, "-vis") || !ft_strcmp(*argv, "-aff")
			|| !ft_strcmp(*argv, "-dump"))
			ft_read_flags_vis_aff_dump(mem, &argc, &argv);
		else if (!ft_strcmp(*argv, "-verb"))
			ft_read_flag_verb(mem, &argc, &argv);
		else if (!ft_strcmp(*argv, "-n"))
			order = ft_read_flag_n(info, &argc, &argv);
		else if (*argv[0] == '-')
			ft_usage_vm();
		else
			ft_read_arg_players(info, *argv, &order);
		argv++;
		argc--;
	}
	if (!info->num_pl)
		ft_usage_vm();
}

void	ft_read_arg_players(t_info_players *info, char *arg, int *order)
{
	if (info->num_pl == MAX_PLAYERS)
		ft_usage_vm();
	info->arg_players[info->num_pl] = arg;
	if (*order)
	{
		info->order_players[info->num_pl] = *order;
		*order = 0;
	}
	info->num_pl++;
}
