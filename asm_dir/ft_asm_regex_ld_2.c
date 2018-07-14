/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_regex_ld_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:24:45 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/22 17:24:46 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

t_handle_func	ft_asm_regex_ld_reg_second(char **str, int *res,
											t_asm_valid *params)
{
	size_t	len;
	char	*str_cpy;

	(void)params;
	ft_asm_skip_symb(str, res);
	len = 0;
	str_cpy = *str;
	while (*str_cpy && ft_isdigit(*str_cpy))
	{
		len++;
		str_cpy++;
	}
	if (len > 0 && len < 3)
	{
		while (len--)
			ft_asm_skip_symb(str, res);
		return ((void*)ft_asm_regex_finish);
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_ld_second_arg(char **str, int *res,
											t_asm_valid *params)
{
	(void)params;
	while (**str && (**str == ' ' || **str == '\t'))
		ft_asm_skip_symb(str, res);
	if (**str == SEPARATOR_CHAR)
	{
		ft_asm_skip_symb(str, res);
		while (**str && (**str == ' ' || **str == '\t'))
			ft_asm_skip_symb(str, res);
		if (**str == REG_CHAR)
			return ((void*)ft_asm_regex_ld_reg_second);
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_ld_save_label(char **str, int *res,
											t_asm_valid *params)
{
	size_t	label_len;
	t_label	*new_label;

	label_len = 0;
	ft_asm_skip_symb(str, res);
	while (**str && ft_strchr(LABEL_CHARS, **str))
	{
		ft_asm_skip_symb(str, res);
		label_len++;
	}
	if (label_len > 0)
	{
		new_label = (t_label*)ft_memalloc(sizeof(t_label));
		new_label->line = params->line_nb;
		new_label->pos = *res - (int)label_len;
		new_label->label = ft_strsub(*str - label_len, 0, label_len);
		ft_al_insert(params->labels_args, new_label);
		return ((void*)ft_asm_regex_ld_second_arg);
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_ld_dir_indir_first(char **str, int *res,
													t_asm_valid *params)
{
	size_t	nb_len;

	(void)params;
	if (**str == '-')
		ft_asm_skip_symb(str, res);
	else if (**str == LABEL_CHAR)
		return ((void*)ft_asm_regex_ld_save_label);
	nb_len = 0;
	while (**str && **str != ' ' && **str != '\t' && **str != SEPARATOR_CHAR)
	{
		if (ft_isdigit(**str) && ft_asm_skip_symb(str, res))
			nb_len++;
		else
			return (NULL);
	}
	if (nb_len > 0)
		return ((void*)ft_asm_regex_ld_second_arg);
	return (NULL);
}
