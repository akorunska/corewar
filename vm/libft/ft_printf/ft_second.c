/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:02 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:16:19 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_newcurlstva(int ss, t_valist *lstva)
{
	int		i;

	va_end((*lstva).arg);
	va_copy((*lstva).arg, (*lstva).arg_first);
	i = 1;
	while (i < ss)
	{
		va_arg((*lstva).arg, void *);
		i++;
	}
}

int		ft_seconddiouxxb(char **str, t_pers par, void *varg)
{
	if (par.tp == 'd')
		ft_printint_di(str, par, varg);
	if (par.tp == 'o')
		ft_printint_o(str, par, varg);
	if (par.tp == 'u')
		ft_printint_u(str, par, varg);
	if ((par.tp == 'x') || (par.tp == 'X'))
		ft_printint_xx(str, par, varg);
	if (par.tp == 'b')
		ft_printint_b(str, par, varg);
	if (!(*str))
		return (-1);
	if (par.tp == 'x')
		ft_aaff(str);
	return (0);
}

int		ft_secondnz(char **str, t_pers par, void *varg, size_t *zlo)
{
	if (par.tp == 's')
		return (ft_printstr(str, par, varg));
	if (par.tp == 'p')
		return (ft_printptr(str, varg));
	if ((par.tp == 'd') || (par.tp == 'o') || (par.tp == 'u')
		|| (par.tp == 'x') || (par.tp == 'X') || (par.tp == 'b'))
		return (ft_seconddiouxxb(str, par, varg));
	if (par.tp == 'c')
		return (ft_printchr(str, par, varg, zlo));
	return (0);
}

int		ft_second(char **str, t_pers par, t_valist *lstva, size_t *zlo)
{
	void	*varg;

	if (par.ss)
		ft_newcurlstva(par.ss, lstva);
	if (((varg = va_arg((*lstva).arg, void *)) == NULL)
		&& (!(par.pr)) && (par.tp != 'c'))
	{
		if (!(*str = ft_strdup("")))
			return (-1);
	}
	else
		return (ft_secondnz(str, par, varg, zlo));
	return (0);
}
