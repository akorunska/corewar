/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_abodnar.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:53:27 by abodnar           #+#    #+#             */
/*   Updated: 2018/05/08 11:53:28 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASM_ABODNAR_H

# define FT_ASM_ABODNAR_H

# include <stdbool.h>
# include "libftprintf/libftprintf.h"
# include "ab_arr_list/ft_ab_arr_list.h"
# include "asm_parse.h"
# include "op.h"

# define READ_SIZE 256

typedef struct		s_label
{
	int				line;
	int				pos;
	char			*label;
}					t_label;

typedef struct		s_asm_valid
{
	int				name;
	int				comment;
	char			*result;
	int				nl_in_name;
	int				nl_in_comment;
	int				len_for_write;
	int				line_nb;
	int				char_nb;
	int				line_count;
	t_array_list	*labels;
	t_array_list	*labels_args;

}					t_asm_valid;

typedef void*	(*t_handle_func)(char**, int*, t_asm_valid *);
typedef int		(*t_regex)(char*, t_asm_valid*);

bool				ft_asm_valid(t_asm_valid *params, t_regex funcs[19],
						char *champ);
int					ft_asm_valid_line(t_regex funcs[19], char *champ,
						t_asm_valid *params);
void				ft_asm_init_regex(t_regex *regex_funcs);
char				*ft_asm_read_file(t_asm_valid *params, char *filename);
int					ft_asm_skip_symb(char **str, int *res);

int					ft_asm_regex_empty_line(char *champ, t_asm_valid *params);
int					ft_asm_regex_champ_name(char *champ, t_asm_valid *params);
int					ft_asm_regex_champ_comment(char *champ,
													t_asm_valid *params);

int					ft_asm_regex_live(char *champ, t_asm_valid *params);
t_handle_func		ft_asm_regex_live_dir(char **str, int *res,
												t_asm_valid *params);
int					ft_asm_regex_ld(char *champ, t_asm_valid *params);
t_handle_func		ft_asm_regex_ld_dir_indir_first(char **str, int *res,
													t_asm_valid *params);
int					ft_asm_regex_st(char *champ, t_asm_valid *params);
t_handle_func		ft_asm_regex_st_second_arg(char **str, int *res,
													t_asm_valid *params);
int					ft_asm_regex_add(char *champ, t_asm_valid *params);
t_handle_func		ft_asm_regex_add_reg_first(char **str, int *res,
													t_asm_valid *params);
int					ft_asm_regex_sub(char *champ, t_asm_valid *params);
int					ft_asm_regex_and(char *champ, t_asm_valid *params);
t_handle_func		ft_asm_regex_aox_reg_first(char **str, int *res,
												t_asm_valid *params);
t_handle_func		ft_asm_regex_aox_dir_indir_first(char **str, int *res,
														t_asm_valid *params);
t_handle_func		ft_asm_regex_aox_reg_second(char **str, int *res,
														t_asm_valid *params);
t_handle_func		ft_asm_regex_aox_save_label_second(char **str, int *res,
														t_asm_valid *params);
t_handle_func		ft_asm_regex_aox_third_arg(char **str, int *res,
													t_asm_valid *params);
int					ft_asm_regex_or(char *champ, t_asm_valid *params);
int					ft_asm_regex_xor(char *champ, t_asm_valid *params);
int					ft_asm_regex_zjmp(char *champ, t_asm_valid *params);
int					ft_asm_regex_ldi(char *champ, t_asm_valid *params);
t_handle_func		ft_asm_regex_ldi_reg_first(char **str, int *res,
												t_asm_valid *params);
t_handle_func		ft_asm_regex_ldi_dir_indir_first(char **str, int *res,
														t_asm_valid *params);
t_handle_func		ft_asm_regex_ldi_dir_second(char **str, int *res,
													t_asm_valid *params);
t_handle_func		ft_asm_regex_ldi_third_arg(char **str, int *res,
														t_asm_valid *params);
int					ft_asm_regex_sti(char *champ, t_asm_valid *params);
t_handle_func		ft_asm_regex_sti_reg_first(char **str, int *res,
													t_asm_valid *params);
t_handle_func		ft_asm_regex_sti_third_arg(char **str, int *res,
													t_asm_valid *params);
int					ft_asm_regex_fork(char *champ, t_asm_valid *params);
int					ft_asm_regex_lld(char *champ, t_asm_valid *params);
int					ft_asm_regex_lldi(char *champ, t_asm_valid *params);
int					ft_asm_regex_lfork(char *champ, t_asm_valid *params);

int					ft_asm_regex_aff(char *champ, t_asm_valid *params);
t_handle_func		ft_asm_regex_aff_reg(char **str, int *res,
													t_asm_valid *params);

t_handle_func		ft_asm_regex_success(char **str, int *res,
													t_asm_valid *params);
t_handle_func		ft_asm_regex_finish(char **str, int *res,
													t_asm_valid *params);

t_handle_func		ft_asm_regex_aox_first_arg(char **str, int *res,
													t_asm_valid *params);
t_handle_func		ft_asm_regex_live_zjmp_fork_lfork_first_arg(char **str,
										int *res, t_asm_valid *params);
t_handle_func		ft_asm_regex_ld_lld_first_arg(char **str, int *res,
													t_asm_valid *params);
t_handle_func		ft_asm_regex_add_sub_first_arg(char **str, int *res,
						t_asm_valid *params);
t_handle_func		ft_asm_regex_ldi_lldi_first_arg(char **str, int *res,
						t_asm_valid *params);

bool				ft_asm_regex_is_duplicated_label(char *label,
						t_asm_valid *params);
bool				ft_asm_labels_matching(t_asm_valid *params);
void				ft_asm_clean_params(t_asm_valid *params);
int					ft_asm_print_error(t_asm_valid params);

#endif
