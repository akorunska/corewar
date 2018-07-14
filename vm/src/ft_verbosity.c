/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbosity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:05:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/17 16:56:59 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_verb_4_part2(t_list_proc *tmp_lst_proc)
{
	if (tmp_lst_proc->command == 12)
		ft_printf(" (%d)", tmp_lst_proc->position
			+ tmp_lst_proc->args_value[0] % IDX_MOD);
	if (tmp_lst_proc->command == 15)
		ft_printf(" (%d)", tmp_lst_proc->position
			+ tmp_lst_proc->args_value[0]);
	ft_printf("\n");
	if (tmp_lst_proc->command == 11)
		ft_printf("%8| -> store to %d + %d = %d (with pc and mod %d)\n",
			tmp_lst_proc->args_value[1], tmp_lst_proc->args_value[2],
			tmp_lst_proc->args_value[1] + tmp_lst_proc->args_value[2],
			tmp_lst_proc->position + (tmp_lst_proc->args_value[1]
			+ tmp_lst_proc->args_value[2]) % IDX_MOD);
	if (tmp_lst_proc->command == 10)
		ft_printf("%8| -> load from %d + %d = %d (with pc and mod %d)\n",
			tmp_lst_proc->args_value[0], tmp_lst_proc->args_value[1],
			tmp_lst_proc->args_value[0] + tmp_lst_proc->args_value[1],
			tmp_lst_proc->position + (tmp_lst_proc->args_value[0]
			+ tmp_lst_proc->args_value[1]) % IDX_MOD);
	if (tmp_lst_proc->command == 14)
		ft_printf("%8| -> load from %d + %d = %d (with pc %d)\n",
			tmp_lst_proc->args_value[0], tmp_lst_proc->args_value[1],
			tmp_lst_proc->args_value[0] + tmp_lst_proc->args_value[1],
			tmp_lst_proc->position + tmp_lst_proc->args_value[0]
			+ tmp_lst_proc->args_value[1]);
}

void		ft_verb_4(t_mem *mem, t_list_proc *tmp_lst_proc)
{
	int		i;

	if (tmp_lst_proc->command == 16 && !mem->aff)
		return ;
	ft_printf("P %4d | %s", tmp_lst_proc->index_number,
		g_op_tab[tmp_lst_proc->index_command].name);
	i = 0;
	while (i < g_op_tab[tmp_lst_proc->index_command].number_arg)
	{
		if (g_op_tab[tmp_lst_proc->index_command].t_args[i] == T_REG)
			ft_printf(" r%d", tmp_lst_proc->args_value[i]);
		else if (tmp_lst_proc->command == 2 || tmp_lst_proc->command == 13)
			ft_printf(" %d", tmp_lst_proc->reg[tmp_lst_proc->args_value[1]
				- 1]);
		else
			ft_printf(" %d", tmp_lst_proc->args_value[i]);
		i++;
	}
	if (tmp_lst_proc->command == 9 && tmp_lst_proc->carry)
		ft_printf(" OK");
	if (tmp_lst_proc->command == 9 && !tmp_lst_proc->carry)
		ft_printf(" FAILED");
	ft_verb_4_part2(tmp_lst_proc);
}

void		ft_verb_16(t_mem *mem, t_list_proc *tmp_lst_proc, int step_position)
{
	int		i;

	ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", step_position,
		tmp_lst_proc->position, tmp_lst_proc->position + step_position);
	i = 0;
	while (i < step_position)
		ft_printf("%.2x ", (unsigned char)mem->str_mem[(tmp_lst_proc->
			position + i++) % MEM_SIZE]);
	ft_printf("\n");
}

void		ft_verb_8(t_mem *mem)
{
	t_list_proc		*tmp_lst_proc;

	tmp_lst_proc = mem->lst_proc;
	while (tmp_lst_proc)
	{
		if (!tmp_lst_proc->alive)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				tmp_lst_proc->index_number, mem->total_cycles
				- tmp_lst_proc->last_live, mem->cycle_to_die);
		tmp_lst_proc = tmp_lst_proc->next;
	}
}
