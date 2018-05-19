/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:53:28 by abodnar           #+#    #+#             */
/*   Updated: 2018/01/12 12:13:18 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_del_list_elem(t_line **list, const int fd)
{
	t_line		*prev;
	t_line		*head;

	prev = NULL;
	head = *list;
	while (head->fd != fd)
	{
		prev = head;
		head = head->next;
	}
	if (prev)
		prev->next = head->next;
	else
		*list = head->next;
	ft_strdel(&head->str);
	free(head);
	return (1);
}

static t_line	*ft_get_curr(t_line **list, const int fd)
{
	t_line	*temp;
	t_line	*new;

	temp = *list;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	new = (t_line*)malloc(sizeof(t_line));
	new->str = ft_strnew(0);
	new->fd = fd;
	new->next = *list;
	*list = new;
	return (new);
}

static int		ft_give_line(char **str, char **line)
{
	char	*temp1;
	char	*temp2;

	if (!ft_strlen(*str))
		return (0);
	temp1 = ft_strchr(*str, '\n');
	*temp1 = '\0';
	*line = ft_strdup(*str);
	temp2 = *str;
	*str = ft_strdup(temp1 + 1);
	ft_strdel(&temp2);
	return (1);
}

static ssize_t	ft_read_fd(char *buff, t_line *curr)
{
	ssize_t	ret;
	char	*temp;

	if (!(ret = read(curr->fd, buff, BUFF_SIZE)))
		return (0);
	buff[ret] = '\0';
	temp = curr->str;
	curr->str = ft_strjoin(temp, buff);
	ft_strdel(&temp);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*list = NULL;
	t_line			*curr;
	char			buff[BUFF_SIZE + 1];
	ssize_t			xr;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	curr = ft_get_curr(&list, fd);
	while (1)
	{
		if (ft_strchr(curr->str, '\n'))
			return (ft_give_line(&(curr->str), line));
		if ((xr = ft_read_fd(buff, curr)) == 0)
		{
			if (!ft_strlen(curr->str) && ft_del_list_elem(&list, fd))
				return (0);
			*line = ft_strdup(curr->str);
			ft_bzero(curr->str, ft_strlen(curr->str));
			return (1);
		}
		if (xr == -1)
			return (-1);
	}
	return (666);
}
