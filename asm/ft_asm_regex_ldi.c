/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_regex_ldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:51:02 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/14 15:51:03 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm_abodnar.h"

t_handle_func	ft_asm_regex_ldi_reg_third(char **str, int *res,
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

t_handle_func	ft_asm_regex_ldi_third_arg(char **str, int *res,
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
			return ((void*)ft_asm_regex_ldi_reg_third);
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_ldi_save_label_second(char **str, int *res,
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
		return ((void*)ft_asm_regex_ldi_third_arg);
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_ldi_dir_second(char **str, int *res,
													t_asm_valid *params)
{
	size_t	nb_len;

	(void)params;
	if (**str == '-')
		ft_asm_skip_symb(str, res);
	else if (**str == LABEL_CHAR)
		return ((void*)ft_asm_regex_ldi_save_label_second);
	nb_len = 0;
	while (**str && **str != ' ' && **str != '\t' && **str != SEPARATOR_CHAR)
	{
		if (ft_isdigit(**str) && ft_asm_skip_symb(str, res))
			nb_len++;
		else
			return (NULL);
	}
	if (nb_len > 0)
		return ((void*)ft_asm_regex_ldi_third_arg);
	return (NULL);
}

t_handle_func	ft_asm_regex_ldi_reg_second(char **str, int *res,
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
		return ((void*)ft_asm_regex_ldi_third_arg);
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_ldi_second_arg(char **str, int *res,
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
			return ((void*)ft_asm_regex_ldi_reg_second);
		else if (**str == DIRECT_CHAR)
		{
			ft_asm_skip_symb(str, res);
			return ((void*)ft_asm_regex_ldi_dir_second);
		}
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_ldi_save_label_first(char **str, int *res,
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
		return ((void*)ft_asm_regex_ldi_second_arg);
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_ldi_dir_indir_first(char **str, int *res,
														t_asm_valid *params)
{
	size_t	nb_len;

	(void)params;
	if (**str == '-')
		ft_asm_skip_symb(str, res);
	else if (**str == LABEL_CHAR)
		return ((void*)ft_asm_regex_ldi_save_label_first);
	nb_len = 0;
	while (**str && **str != ' ' && **str != '\t' && **str != SEPARATOR_CHAR)
	{
		if (ft_isdigit(**str) && ft_asm_skip_symb(str, res))
			nb_len++;
		else
			return (NULL);
	}
	if (nb_len > 0)
		return ((void*)ft_asm_regex_ldi_second_arg);
	return (NULL);
}

t_handle_func	ft_asm_regex_ldi_reg_first(char **str, int *res,
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
		return ((void*)ft_asm_regex_ldi_second_arg);
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_ldi_lldi_first_arg(char **str, int *res,
														t_asm_valid *params)
{
	(void)params;
	while (**str && (**str == ' ' || **str == '\t'))
		ft_asm_skip_symb(str, res);
	if (**str == REG_CHAR)
		return ((void*)ft_asm_regex_ldi_reg_first);
	else if (**str == DIRECT_CHAR)
	{
		ft_asm_skip_symb(str, res);
		return ((void*)ft_asm_regex_ldi_dir_indir_first);
	}
	else if (**str == '-' || **str == LABEL_CHAR || ft_isdigit(**str))
		return ((void*)ft_asm_regex_ldi_dir_indir_first);
	return (NULL);
}

t_handle_func	ft_asm_regex_ldi_after_label(char **str, int *res,
													t_asm_valid *params)
{
	int		i;
	int		cmd_name_len;

	(void)params;
	while (**str && (**str == ' ' || **str == '\t'))
		ft_asm_skip_symb(str, res);
	cmd_name_len = (int)ft_strlen(g_op_tab[9].name);
	if (ft_strnequ(*str, g_op_tab[9].name, (size_t)cmd_name_len))
	{
		i = -1;
		while (++i < cmd_name_len)
			ft_asm_skip_symb(str, res);
		return ((void*)ft_asm_regex_ldi_lldi_first_arg);
	}
	return (NULL);
}

t_handle_func	ft_asm_regex_ldi_save_start_label(char **str, int *res,
														t_asm_valid *params)
{
	int		label_len;
	char	*new_label;

	label_len = 0;
	while (**str && **str != LABEL_CHAR)
		if (ft_strchr(LABEL_CHARS, **str) && ft_asm_skip_symb(str, res))
			label_len++;
		else
			return (NULL);
	new_label = ft_strsub(*str - label_len, 0, (size_t)label_len);
	if (ft_asm_regex_is_duplicated_label(new_label, params))
	{
		ft_strdel(&new_label);
		ft_asm_skip_symb(str, res);
		return ((void*)ft_asm_regex_ldi_after_label);
	}
	ft_al_insert(params->labels, (void*)new_label);
	ft_asm_skip_symb(str, res);
	while (**str && (**str == ' ' || **str == '\t'))
		ft_asm_skip_symb(str, res);
	if (**str == '\n')
		return ((void*)ft_asm_regex_success);
	else if (**str == COMMENT_CHAR || **str == COMMENT_CHAR_ADD)
		return ((void*)ft_asm_regex_finish);
	return ((void*)ft_asm_regex_ldi_after_label);
}

t_handle_func	ft_asm_regex_ldi_start(char **str, int *res,
												t_asm_valid *params)
{
	char	*label_end;

	(void)params;
	while (**str && (**str == ' ' || **str == '\t'))
		ft_asm_skip_symb(str, res);
	if ((label_end = ft_strchr(*str, LABEL_CHAR)) != NULL
		&& label_end < ft_strchr(*str, '\n')
		&& ft_strchr(LABEL_CHARS, *(label_end - 1)))
		return ((void*)ft_asm_regex_ldi_save_start_label);
	return ((void*)ft_asm_regex_ldi_after_label);
}

int				ft_asm_regex_ldi(char *champ, t_asm_valid *params)
{
	int				res;
	t_handle_func	func_curr;

	(void)params;
	func_curr = (t_handle_func)ft_asm_regex_ldi_start;
	res = 1;
	while (*champ && (*champ == ' ' || *champ == '\t'))
		ft_asm_skip_symb(&champ, &res);
	while (*champ)
	{
		if (*func_curr == (void*)ft_asm_regex_success)
			return (-1);
		else if (*func_curr == NULL)
			return (res);
		func_curr = (t_handle_func)func_curr(&champ, &res, params);
	}
	if (*(champ - 1) == '\n')
		return (-1);
	return (res);
}
