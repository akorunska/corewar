/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_write_players.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:25:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/07 18:07:13 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_read_players(t_mem *mem, t_info_players *info)
{
	while (mem->num_pl < info->num_pl)
	{
		close(ft_open_read(mem, info, &info->binary_players[mem->num_pl],
			info->arg_players[mem->num_pl]));
		mem->num_pl++;
	}
	ft_write_players_in_mem(mem, info);
}

int		ft_open_read(t_mem *mem, t_info_players *info, t_binary_players *player,
						char *line)
{
	size_t	size_file;
	int		fd;

	if ((fd = open(line, O_RDONLY)) == -1)
		ft_error_open(mem, info);
	if ((size_file = (size_t)lseek(fd, 0, SEEK_END)) > sizeof(t_header)
		+ CHAMP_MAX_SIZE)
		ft_error_size_max(mem, info);
	lseek(fd, 0, SEEK_SET);
	if (!(player->head = (t_header *)malloc(sizeof(t_header))))
		ft_error_malloc(mem, info);
	if (read(fd, player->head, sizeof(t_header)) == -1)
		ft_error_read(mem, info);
	if ((player->head->magic = ft_swaps_bits_int(player->
		head->magic)) != COREWAR_EXEC_MAGIC)
		ft_error_magic(mem, info);
	player->head->prog_size = ft_swaps_bits_int(player->head->prog_size);
	if (size_file - sizeof(t_header) != player->head->prog_size)
		ft_error_size_diff(mem, info);
	if (!(player->prog = (unsigned char *)ft_strnew(size_file
		- sizeof(t_header))))
		ft_error_malloc(mem, info);
	if (read(fd, player->prog, size_file - sizeof(t_header)) == -1)
		ft_error_read(mem, info);
	return (fd);
}

void	ft_write_players_in_mem(t_mem *mem, t_info_players *info)
{
	int					start;
	int					pl;
	unsigned int		i;

	pl = 0;
	while (pl < info->num_pl)
	{
		start = pl * MEM_SIZE / info->num_pl;
		i = 0;
		while (i < info->binary_players[pl].head->prog_size)
		{
			mem->str_mem[start] = info->binary_players[pl].prog[i++];
			if (mem->visual)
				mem->str_mem_pl[start] = (char)(pl + 1);
			start++;
		}
		mem->id_winner = ++pl;
	}
}
