/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args_from_memory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:42:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/17 17:09:35 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_get_args_from_memory_dir(t_mem *mem, t_list_proc *tmp_lst_proc,
										int *step)
{
	int		value;

	if (!g_op_tab[tmp_lst_proc->index_command].label_size)
	{
		value = ft_get_memory(mem->str_mem,
			tmp_lst_proc->position + *step, DIR_SIZE);
		*step += DIR_SIZE;
	}
	else
	{
		value = (short int)ft_get_memory(mem->str_mem,
			tmp_lst_proc->position + *step, DIR_SIZE / 2);
		*step += DIR_SIZE / 2;
	}
	return (value);
}

int			ft_get_args_from_memory(t_mem *mem, t_list_proc *tmp_lst_proc,
									int *step)
{
	int		i;
	int		ret;

	ret = ft_check_codage_octal(tmp_lst_proc);
	i = 0;
	while (i < g_op_tab[tmp_lst_proc->index_command].number_arg)
	{
		if (tmp_lst_proc->args_code[i] == REG_CODE)
			tmp_lst_proc->args_value[i] = mem->str_mem[(tmp_lst_proc->position
				+ (*step)++) % MEM_SIZE];
		if (tmp_lst_proc->args_code[i] == DIR_CODE)
			tmp_lst_proc->args_value[i] = ft_get_args_from_memory_dir(mem,
				tmp_lst_proc, step);
		if (tmp_lst_proc->args_code[i] == IND_CODE)
		{
			tmp_lst_proc->args_value[i] = (short int)ft_get_memory(mem->str_mem,
				tmp_lst_proc->position + *step, IND_SIZE);
			*step += IND_SIZE;
		}
		i++;
	}
	if (!ret)
		ret = ft_check_reg_counters(tmp_lst_proc);
	return (ret);
}

int			ft_check_codage_octal(t_list_proc *tmp_lst_proc)
{
	int			i;
	t_arg_type	t_arg;

	i = 0;
	while (i < g_op_tab[tmp_lst_proc->index_command].number_arg)
	{
		t_arg = ft_arg_conv_code_to_type(tmp_lst_proc->args_code[i]);
		if (!(g_op_tab[tmp_lst_proc->index_command].t_args[i] & t_arg))
			return (-1);
		i++;
	}
	return (0);
}

int			ft_check_reg_counters(t_list_proc *tmp_lst_proc)
{
	int		i;

	i = 0;
	while (i < g_op_tab[tmp_lst_proc->index_command].number_arg)
	{
		if (tmp_lst_proc->args_code[i] == REG_CODE
			&& (tmp_lst_proc->args_value[i] < 1
			|| tmp_lst_proc->args_value[i] > REG_NUMBER))
			return (-1);
		i++;
	}
	return (0);
}
