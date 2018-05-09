/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:41:25 by akorunsk          #+#    #+#             */
/*   Updated: 2017/11/27 18:24:13 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 256

typedef struct		s_remains
{
	struct s_remains	*prev;
	int					fd;
	char				*str;
	struct s_remains	*next;
}					t_remains;

int					get_next_line(const int fd, char **line);

#endif
