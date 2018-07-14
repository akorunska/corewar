/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_regex_is_duplicated_label.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:16:24 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/17 14:16:25 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

bool	ft_asm_regex_is_duplicated_label(char *label, t_asm_valid *params)
{
	int		i;
	char	**all_labels;

	i = -1;
	all_labels = (char**)params->labels->data;
	while (++i < params->labels->size)
	{
		if (ft_strequ(label, *all_labels))
			return (1);
		all_labels++;
	}
	return (0);
}
