/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_labels_matching.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:45:30 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/17 14:45:31 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

bool	ft_asm_labels_matching(t_asm_valid *params)
{
	int		i;
	int		j;
	bool	match;
	char	**labels;
	t_label	**label_args;

	labels = (char**)params->labels->data;
	label_args = (t_label**)params->labels_args->data;
	i = -1;
	while (++i < params->labels_args->size)
	{
		match = 0;
		j = -1;
		while (++j < params->labels->size)
		{
			if (ft_strequ(label_args[i]->label, labels[j]))
			{
				match = 1;
				break ;
			}
		}
		if (match == 0)
		{
			params->line_nb = label_args[i]->line;
			params->char_nb = label_args[i]->pos;
			return (0);
		}
	}
	ft_printf("Labels OK!\n");
	return (1);
}
