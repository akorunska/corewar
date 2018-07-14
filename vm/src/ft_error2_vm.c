/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:37:30 by ddenkin           #+#    #+#             */
/*   Updated: 2018/05/22 17:09:38 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_error_size_max(t_mem *mem, t_info_players *info)
{
	ft_frees_vm(mem, info);
	ft_putstr_fd("Error, file too large.\n", 2);
	exit(1);
}

void	ft_error_size_diff(t_mem *mem, t_info_players *info)
{
	ft_frees_vm(mem, info);
	ft_putstr_fd("Error, specified champion size differs from actual size.\n",
				2);
	exit(1);
}

void	ft_error_init_nc(t_mem *mem, t_info_players *info)
{
	ft_frees_vm(mem, info);
	ft_putstr_fd("Failed to initialise ncurses.\n", 2);
	exit(1);
}

void	ft_error_colors_nc(t_mem *mem, t_info_players *info)
{
	ft_frees_vm(mem, info);
	ft_putstr_fd("Missing required color support.\n", 2);
	exit(1);
}
