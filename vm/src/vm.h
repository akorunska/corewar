/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:10:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/05/19 18:12:03 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "curses.h"
# include "op.h"
# include <sys/time.h>

# define MINUSES "--------------------------------------------------"

typedef struct			s_list_proc
{
	int					reg[REG_NUMBER];
	int					position;
	int					freeze;
	int					alive;
	char				command;
	int					index_command;
	char				args_code[4];
	int					args_value[4];
	int					carry;
	char				pl;
	int					index_number;
	int					last_live;
	struct s_list_proc	*next;
}						t_list_proc;

typedef struct			s_mem
{
	char				*str_mem;
	char				*str_mem_pl;
	char				*str_mem_bold;
	char				*str_mem_inv;
	char				*str_mem_live;
	t_list_proc			*lst_proc;
	int					lst_length;
	int					num_pl;
	int					sum_alive;
	int					id_winner;
	int					total_cycles;
	int					nbr_cycles;
	int					cur_cycles;
	int					cycle_to_die;
	int					checks;
	char				verb[6];
	int					visual;
	int					aff;
	int					paused;
	int					limit;
}						t_mem;

typedef struct			s_binary_players
{
	t_header			*head;
	unsigned char		*prog;
}						t_binary_players;

typedef struct			s_info_players
{
	int					num_pl;
	char				*arg_players[MAX_PLAYERS];
	t_binary_players	binary_players[MAX_PLAYERS];
	int					order_players[MAX_PLAYERS];
	int					live[MAX_PLAYERS];
	int					last_live[MAX_PLAYERS];
}						t_info_players;

void					ft_read_main_arg(t_mem *mem, t_info_players *info,
										int argc, char **argv);
void					ft_read_arg_players(t_info_players *info, char *arg,
											int *order);

void					ft_read_flags_vis_aff_dump(t_mem *mem, int *argc,
												char ***argv);
void					ft_read_flag_verb(t_mem *mem, int *argc, char ***argv);
int						ft_read_flag_n(t_info_players *info, int *argc,
										char ***argv);
int						ft_check_doubles_order(t_info_players *info, int order);

void					ft_read_players(t_mem *mem, t_info_players *info);
int						ft_open_read(t_mem *mem, t_info_players *info,
										t_binary_players *player, char *line);
void					ft_write_players_in_mem(t_mem *mem,
												t_info_players *info);

void					ft_create_processes(t_mem *mem, t_info_players *info);
void					ft_order_processes(t_info_players *info);
int						ft_check_have_this_order(t_info_players *info,
													int cur_num);

void					ft_start_battle_without_nc(t_mem *mem,
												t_info_players *info);

void					ft_start_battle_with_nc(t_mem *mem,
												t_info_players *info);

void					ft_cycle_of_battle(t_mem *mem, t_info_players *info);
void					ft_del_dead_processes(t_mem *mem);
void					ft_zero_alive(t_mem *mem, t_info_players *info);

void					ft_one_cycle_processes(t_mem *mem,
											t_info_players *info);
void					ft_add_command_to_process_or_not(t_mem *mem,
													t_list_proc *tmp_lst_proc);

int						ft_codage_octal(t_mem *mem, t_list_proc *tmp_lst_proc);
void					ft_read_codage_octal(t_list_proc *tmp_lst_proc,
										unsigned char codage_octal);
char					ft_two_bits_codage_octal(unsigned char codage_octal,
												int i);

int						ft_get_args_from_memory(t_mem *mem,
								t_list_proc *tmp_lst_proc, int *step_position);
int						ft_check_codage_octal(t_list_proc *tmp_lst_proc);
int						ft_check_reg_counters(t_list_proc *tmp_lst_proc);

void					ft_execution_command(t_mem *mem, t_info_players *info,
											t_list_proc *tmp_lst_proc);
void					ft_zero_command_and_args_in_proc(t_list_proc
														*tmp_lst_proc);

int						ft_get_memory(char const *mem, int position, int size);
int						ft_set_memory(char *mem, int position, int value);

char					ft_arg_conv_type_to_code(t_arg_type t_arg);
t_arg_type				ft_arg_conv_code_to_type(char arg);

int						ft_carry_0_or_1(int value);

int						ft_live(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_ld(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_st(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_add(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_sub(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_and(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_or(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_xor(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_zjmp(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_ldi(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_sti(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_fork(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_lld(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_lldi(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_lfork(t_mem *mem, t_list_proc *tmp_lst_proc);
int						ft_aff(t_mem *mem, t_list_proc *tmp_lst_proc);

void					ft_output_head(t_info_players *info);
void					ft_output_memory(t_mem *mem);

void					ft_frees_vm(t_mem *mem, t_info_players *info);
void					ft_frees_mem(t_mem *mem);
void					ft_frees_info(t_info_players *info);

void					ft_usage_vm(void);
void					ft_error_malloc(t_mem *mem, t_info_players *info);
void					ft_error_open(t_mem *mem, t_info_players *info);
void					ft_error_read(t_mem *mem, t_info_players *info);
void					ft_error_magic(t_mem *mem, t_info_players *info);

void					ft_error_size_max(t_mem *mem, t_info_players *info);
void					ft_error_size_diff(t_mem *mem, t_info_players *info);
void					ft_error_init_nc(t_mem *mem, t_info_players *info);
void					ft_error_colors_nc(t_mem *mem, t_info_players *info);

void					ft_verb_4(t_mem *mem, t_list_proc *tmp_lst_proc);
void					ft_verb_16(t_mem *mem, t_list_proc *tmp_lst_proc,
								int step_position);
void					ft_verb_8(t_mem *mem);

t_list_proc				*ft_lstprocnew(int position, char pl);
void					ft_lstprocadd(t_list_proc **alst, t_list_proc *new);
void					ft_lstprocdeloneany(t_list_proc **alst,
											t_list_proc **clst);
void					ft_lstprocdel(t_list_proc **alst);

int						ft_atoi_vm(const char *str);
int						init_ncurses(void);
void					winner(t_mem *mem, t_info_players *info);
void					proper_init(t_mem *mem, t_info_players *info);

void					print_pl_info(t_info_players *info, int num);
int						ft_sum(const int *arr, int size);
void					small_pl_stat(t_info_players *info,
								int count[MAX_PLAYERS], int arr[MAX_PLAYERS]);
void					print_perc(int arr[MAX_PLAYERS], t_info_players *info,
							t_mem *mem, int save[MAX_PLAYERS]);
void					print_breakdown(t_mem *mem, t_info_players *info);

typedef int				(*t_op_arr_of_function)(t_mem *, t_list_proc *);

static const			t_op_arr_of_function	g_op_arr_of_com[17] =
{
	ft_live,
	ft_ld,
	ft_st,
	ft_add,
	ft_sub,
	ft_and,
	ft_or,
	ft_xor,
	ft_zjmp,
	ft_ldi,
	ft_sti,
	ft_fork,
	ft_lld,
	ft_lldi,
	ft_lfork,
	ft_aff,
	NULL
};

#endif
