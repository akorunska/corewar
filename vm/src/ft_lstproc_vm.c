/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstproc_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:23:55 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/12 20:31:15 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_lstprocnew_init(t_list_proc *elem)
{
	elem->freeze = 0;
	elem->alive = 0;
	elem->command = 0;
	elem->index_command = 0;
	elem->carry = 0;
	elem->last_live = 0;
}

t_list_proc	*ft_lstprocnew(int position, char pl)
{
	t_list_proc		*elem;
	int				i;
	static int		index_number = 1;

	if (!(elem = (t_list_proc*)malloc(sizeof(t_list_proc))))
		return (NULL);
	ft_lstprocnew_init(elem);
	i = 0;
	while (i < REG_NUMBER)
		elem->reg[i++] = 0;
	elem->position = position;
	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		elem->args_code[i] = 0;
		elem->args_value[i++] = 0;
	}
	elem->pl = pl;
	elem->index_number = index_number++;
	elem->next = NULL;
	return (elem);
}

void		ft_lstprocadd(t_list_proc **alst, t_list_proc *new)
{
	if ((alst != NULL) && (new != NULL))
	{
		new->next = *alst;
		*alst = new;
	}
}

void		ft_lstprocdeloneany(t_list_proc **alst, t_list_proc **clst)
{
	t_list_proc		*tmp;

	if (alst && clst)
	{
		if (*alst == *clst)
			*alst = (*alst)->next;
		else
		{
			tmp = *alst;
			while (tmp->next)
			{
				if (tmp->next == *clst)
				{
					tmp->next = (*clst)->next;
					break ;
				}
				tmp = tmp->next;
			}
		}
		free(*clst);
		*clst = NULL;
	}
}

void		ft_lstprocdel(t_list_proc **alst)
{
	t_list_proc		*tmp;

	if (alst)
	{
		while (*alst)
		{
			tmp = *alst;
			*alst = (*alst)->next;
			free(tmp);
			tmp = NULL;
		}
		alst = NULL;
	}
}
