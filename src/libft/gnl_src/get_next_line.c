/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:41:23 by akorunsk          #+#    #+#             */
/*   Updated: 2017/11/27 18:18:25 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "../libft.h"
#include <stdlib.h>

/*
**  -1 	-- error
** 	-2 	-- go out of function
** 	1 	-- continue reading
*/

int			delete(t_remains **to_del)
{
	t_remains	*d;

	if (*to_del)
	{
		d = *to_del;
		if (d->prev)
			d->prev->next = d->next;
		if (d->next)
			d->next->prev = d->prev;
		if ((*to_del)->str)
			free((*to_del)->str);
		ft_memdel((void **)to_del);
	}
	return (0);
}

t_remains	*find(t_remains *head, int fd)
{
	t_remains	*prev;
	t_remains	*n;

	prev = NULL;
	while (head)
	{
		if (head->fd == fd)
			return (head);
		prev = head;
		head = head->next;
	}
	n = (t_remains *)malloc(sizeof(t_remains));
	if (!n)
		return (NULL);
	n->fd = fd;
	n->next = NULL;
	n->prev = prev;
	n->str = NULL;
	if (prev)
		prev->next = n;
	return (n);
}

int			append(int read_q, char **line, char *buf, t_remains *prev)
{
	char	*pos;
	char	*temp;

	read_q++;
	pos = ft_memchr(buf, '\n', ft_strlen(buf));
	if (!pos)
	{
		temp = ft_strjoin(*line, buf);
		free(*line);
		*line = temp;
		return (1);
	}
	if (prev->str)
		free(prev->str);
	prev->str = ft_strsub(buf, (pos + 1) - buf, ft_strchr(buf, '\0') - pos - 1);
	*pos = '\0';
	temp = ft_strjoin(*line, buf);
	free(*line);
	*line = temp;
	if (!temp)
		return (-1);
	return (-2);
}

int			get_prev_line(char **line, t_remains **p, const int fd, char **buf)
{
	static	t_remains	*head;
	char				*b;
	int					rv;

	*p = NULL;
	*buf = NULL;
	if (BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (!(*buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	*line = ft_strnew(1);
	*p = find(head, fd);
	if (!(*p))
		return (-1);
	if (!head)
		head = *p;
	if ((*p)->fd == fd && (*p)->str != NULL)
	{
		b = ft_strdup((*p)->str);
		rv = append((ft_strlen((*p)->str)), line, b, *p);
		free(b);
		return (rv);
	}
	else
		return (1);
}

int			get_next_line(const int fd, char **line)
{
	t_remains	*prev;
	char		*buf;
	int			read_q;
	int			initial;

	read_q = get_prev_line(line, &prev, fd, &buf);
	initial = 1;
	while (read_q > 0 && line)
	{
		if ((read_q = read(fd, buf, BUFF_SIZE)) <= 0)
			break ;
		initial = 0;
		buf[read_q] = '\0';
		read_q = append(read_q, line, buf, prev);
	}
	if (read_q == -1)
		return (-1);
	free(buf);
	return ((read_q == 0 && initial) ? 0 : 1);
}
