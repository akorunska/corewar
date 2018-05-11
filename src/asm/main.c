/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:41:46 by akorunsk          #+#    #+#             */
/*   Updated: 2018/05/07 12:41:49 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> //
#include "asm_parse.h"

#define FILE_SIZE 64

int		main(int	argc, char **argv)
{
	int		i;
	int		fd;
	char	**file_contents;
	char	*buf;
	char	*res;

	file_contents = (char**)malloc(sizeof(char*) * (FILE_SIZE + 1));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			exit(1);
		i = 0;
		while (get_next_line(fd, &buf) == 1)
		{
			file_contents[i] = ft_strtrim(buf);
			free(buf);
			i++;
		}
		file_contents[i] = NULL;
		res = get_bytecode(file_contents);
	}
	return (0);
}