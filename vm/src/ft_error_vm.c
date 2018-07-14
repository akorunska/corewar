/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_vm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:22:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/22 17:07:42 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_usage_vm(void)
{
	ft_printf("usage: ./corewar [-dump N | -verb N | -vis] [-n N] "
					"<champion1.cor> <...>\n"
		"-n N      : Defines specific order for processes\n"
		"-dump N   : Dumps memory after N cycles then exits\n"
		"-aff      : Prints output from \"aff\" (Default is to hide it)\n"
		"#### TEXT OUTPUT MODE ##############################################"
					"####\n"
		"-verb N   : Verbosity levels, can be added together to enable "
					"multiple\n"
		"-  1 : Show lives\n"
		"-  2 : Show cycles\n"
		"-  4 : Show operations (Params are NOT litteral ...)\n"
		"-  8 : Show deaths\n"
		"- 16 : Show PC movements (Except for jumps)\n"
		"#### NCURSES OUTPUT MODE ############################################"
					"###\n"
		"-vis      : Ncurses output mode\n"
		"######################################################################"
					"##\n");
	exit(0);
}

void	ft_error_malloc(t_mem *mem, t_info_players *info)
{
	ft_frees_vm(mem, info);
	ft_putstr_fd("Unable to malloc required memory. Shutting down.\n", 2);
	exit(1);
}

void	ft_error_open(t_mem *mem, t_info_players *info)
{
	ft_frees_vm(mem, info);
	ft_putstr_fd("Encountered error trying to open file.\n", 2);
	exit(1);
}

void	ft_error_read(t_mem *mem, t_info_players *info)
{
	ft_frees_vm(mem, info);
	ft_putstr_fd("Encountered error trying to read file.\n", 2);
	exit(1);
}

void	ft_error_magic(t_mem *mem, t_info_players *info)
{
	ft_frees_vm(mem, info);
	ft_putstr_fd("Missing or invalid magic number.\n", 2);
	exit(1);
}
