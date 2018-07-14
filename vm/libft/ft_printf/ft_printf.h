/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:11:46 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/04 19:39:51 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_pers
{
	int				t;
	int				fd;
	void			*nn;
	int				fl1;
	int				fl2;
	int				fl3;
	int				fl4;
	int				fl5;
	int				wd;
	int				pr;
	int				ln;
	char			tp;
	int				ss;
}					t_pers;

typedef struct		s_valist
{
	va_list			arg_first;
	va_list			arg;
}					t_valist;

typedef struct		s_col
{
	char			*col1;
	char			*col2;
	int				size1;
	int				size2;
	int				num;
}					t_col;

void				ft_zero_printf(t_list **lstf, t_pers *par);
int					ft_findpersent(t_list **lstf, int *t, const char *fmt);
int					ft_needlines(t_list *tmp, t_pers *par,
									const char *fmt, t_valist *lstva);
int					ft_errors(t_list **lstf);

char				*ft_itoa_base_u(intmax_t n, int base, int b);
int					ft_ordernum_base_u(intmax_t d, int base, int b);

void				ft_flags_null(t_pers *par);
void				ft_order(int *t, const char *fmt, t_pers *par);
void				ft_flags(int *t, const char *fmt, t_pers *par);
int					ft_orderfieldprec(int *t, const char *fmt, t_valist *lstva);

void				ft_length(int *t, const char *fmt, t_pers *par);
void				ft_types(int *t, const char *fmt, t_pers *par);
void				ft_persent(int *t, const char *fmt, t_pers *par,
								t_valist *lstva);

int					ft_printpct(char **str, unsigned char c);

void				ft_newcurlstva(int ss, t_valist *lstva);
int					ft_seconddiouxxb(char **str, t_pers par, void *varg);
int					ft_secondnz(char **str, t_pers par,
									void *varg, size_t *zlo);
int					ft_second(char **str, t_pers par,
								t_valist *lstva, size_t *zlo);

void				ft_aaff(char **str);

void				ft_printint_di(char **str, t_pers par, void *d);
void				ft_printint_o(char **str, t_pers par, void *d);
void				ft_printint_u(char **str, t_pers par, void *d);
void				ft_printint_xx(char **str, t_pers par, void *d);
void				ft_printint_b(char **str, t_pers par, void *d);

int					ft_printstr_list(char **str, t_pers par, void *s);
int					ft_printstr(char **str, t_pers par, void *s);
int					ft_printptr(char **str, void *p);
int					ft_printchr(char **str, t_pers par, void *c, size_t *zlo);

int					ft_bitone(char **sb, int d);
int					ft_bittwo(char **sb, int d);
int					ft_bitthree(char **sb, int d);
int					ft_bitfour(char **sb, int d);
int					ft_numsbits(char **sb, int d);

int					ft_precisionss(char **str, char **tmp, t_pers par, int len);
int					ft_precisiondiouxxbp(char **str, char **tmp,
											t_pers par, int len);
int					ft_precision(char **str, char **tmp, t_pers par, int len);

int					ft_realflags(char **str, t_pers par);
void				ft_width_0(char **str, t_pers par, int i);
int					ft_width(char **str, char **tmp, t_pers par, int *len);
int					ft_writepersent(char **str, t_pers par);

size_t				ft_strchrlen(t_list **lstf);
int					ft_tofin(t_list **lstf, t_valist *lstva);

char				*ft_lsttostrzlo(t_list **begin, int len);

void				ft_zerocol(t_col *col);
int					ft_checkcolor(char *str, t_col *col);
void				ft_writecolor(t_col *col);
int					ft_findcolors(int len, char *str);

#endif
