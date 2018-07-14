/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_codage_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:46:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/07 18:07:13 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_codage_octal(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	int		i;

	i = 0;
	if (g_op_tab[tmp_lst_proc->index_command].codage_octal)
	{
		ft_read_codage_octal(tmp_lst_proc, (unsigned char)mem->
			str_mem[(tmp_lst_proc->position + 1) % MEM_SIZE]);
		return (1);
	}
	else
	{
		while (i < g_op_tab[tmp_lst_proc->index_command].number_arg)
		{
			tmp_lst_proc->
				args_code[i] = ft_arg_conv_type_to_code(g_op_tab[tmp_lst_proc->
				index_command].t_args[i]);
			i++;
		}
		return (0);
	}
}

void	ft_read_codage_octal(t_list_proc *tmp_lst_proc,
								unsigned char codage_octal)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		tmp_lst_proc->args_code[i] = ft_two_bits_codage_octal(codage_octal, i);
		i++;
	}
}

char	ft_two_bits_codage_octal(unsigned char codage_octal, int i)
{
	char	tmp;

	tmp = 0;
	if (i == 0)
		tmp = codage_octal >> 6;
	if (i == 1)
		tmp = (codage_octal >> 4) - (codage_octal >> 6 << 2);
	if (i == 2)
		tmp = (codage_octal >> 2) - (codage_octal >> 4 << 2);
	if (i == 3)
		tmp = codage_octal - (codage_octal >> 2 << 2);
	return (tmp);
}
