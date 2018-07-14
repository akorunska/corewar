/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:27:34 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/04 19:11:34 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_findfd(const int fd, t_list **lstfd, t_list **lsttmp)
{
	*lsttmp = *lstfd;
	while (*lsttmp)
	{
		if ((*lsttmp)->content_size == (size_t)fd)
			return (1);
		*lsttmp = (*lsttmp)->next;
	}
	if ((*lsttmp = ft_lstnew(NULL, 0)) == NULL)
		return (-1);
	(*lsttmp)->content_size = (size_t)fd;
	ft_lstadd(lstfd, *lsttmp);
	return (1);
}

static void		ft_lstdeloneandcon(const int fd, t_list **lstfd)
{
	t_list			*lsttmp;
	t_list			*lstlast;

	lsttmp = *lstfd;
	lstlast = NULL;
	while (lsttmp)
	{
		if (lsttmp->content_size == (size_t)fd)
		{
			if (lsttmp == *lstfd)
				*lstfd = lsttmp->next;
			else
				lstlast->next = lsttmp->next;
			free(lsttmp);
			lsttmp = NULL;
			break ;
		}
		lstlast = lsttmp;
		lsttmp = lsttmp->next;
	}
}

static int		ft_writeline(void **str, char **line)
{
	size_t			i;
	char			*strtmp;

	i = 0;
	while ((((char *)*str)[i] != '\n') && (((char *)*str)[i] != '\0'))
		i++;
	if ((*line = ft_strsub(*str, 0, i)) == NULL)
		return (-1);
	if (((char *)*str)[i] == '\n')
	{
		strtmp = *str;
		if ((*str = ft_strsub(*str, i + 1, ft_strlen(*str) - i - 1)) == NULL)
			return (-1);
		ft_strdel(&strtmp);
		if (((char *)*str)[0] == '\0')
			ft_memdel(str);
	}
	else
		ft_memdel(str);
	return (1);
}

static int		ft_loop(const int fd, void **str, char **line, t_list **lstfd)
{
	int				i;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*strtmp;

	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		strtmp = *str;
		if ((*str = ft_strjoin(*str, buf)) == NULL)
			return (-1);
		ft_strdel(&strtmp);
		while (((char *)*str)[i])
			if (((char *)*str)[i++] == '\n')
				return (ft_writeline(str, line));
	}
	if (*str)
		return (ft_writeline(str, line));
	ft_lstdeloneandcon(fd, lstfd);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lstfd = NULL;
	t_list			*lsttmp;

	if ((ft_findfd(fd, &lstfd, &lsttmp)) == -1)
		return (-1);
	if ((lsttmp->content == NULL) || (ft_strchr(lsttmp->content, '\n') == NULL))
		return (ft_loop(fd, &(lsttmp->content), line, &lstfd));
	return (ft_writeline(&(lsttmp->content), line));
}
