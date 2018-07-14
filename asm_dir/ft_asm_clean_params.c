/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_clean_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:31:12 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/19 15:31:14 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

void	ft_asm_clean_params(t_asm_valid *params)
{
	t_label	**labels_args;
	char	**labels;
	int		i;

	labels_args = (t_label**)params->labels_args->data;
	i = -1;
	while (++i < params->labels_args->size)
	{
		free(labels_args[i]->label);
		free(labels_args[i]);
	}
	free(labels_args);
	labels = (char**)params->labels->data;
	i = -1;
	while (++i < params->labels->size)
		free(labels[i]);
	free(labels);
	free(params->labels);
	free(params->labels_args);
	free(params->result);
}
