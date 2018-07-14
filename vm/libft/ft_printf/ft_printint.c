/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:15:14 by igaliuk           #+#    #+#             */
/*   Updated: 2017/12/27 16:15:19 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printint_di(char **str, t_pers par, void *d)
{
	if (par.ln == 0)
		*str = ft_itoa_base_u((int)d, 10, 0);
	if (par.ln == 1)
		*str = ft_itoa_base_u((char)d, 10, 0);
	if (par.ln == 2)
		*str = ft_itoa_base_u((short)d, 10, 0);
	if (par.ln == 3)
		*str = ft_itoa_base_u((long)d, 10, 0);
	if (par.ln == 4)
		*str = ft_itoa_base_u((long long)d, 10, 0);
	if (par.ln == 5)
		*str = ft_itoa_base_u((intmax_t)d, 10, 0);
	if (par.ln == 6)
		*str = ft_itoa_base_u((size_t)d, 10, 0);
}

void	ft_printint_o(char **str, t_pers par, void *d)
{
	if (par.ln == 0)
		*str = ft_itoa_base_u((unsigned int)d, 8, 1);
	if (par.ln == 1)
		*str = ft_itoa_base_u((unsigned char)d, 8, 1);
	if (par.ln == 2)
		*str = ft_itoa_base_u((unsigned short)d, 8, 1);
	if (par.ln == 3)
		*str = ft_itoa_base_u((unsigned long)d, 8, 1);
	if (par.ln == 4)
		*str = ft_itoa_base_u((unsigned long long)d, 8, 1);
	if (par.ln == 5)
		*str = ft_itoa_base_u((uintmax_t)d, 8, 1);
	if (par.ln == 6)
		*str = ft_itoa_base_u((size_t)d, 8, 1);
}

void	ft_printint_u(char **str, t_pers par, void *d)
{
	if (par.ln == 0)
		*str = ft_itoa_base_u((unsigned int)d, 10, 1);
	if (par.ln == 1)
		*str = ft_itoa_base_u((unsigned char)d, 10, 1);
	if (par.ln == 2)
		*str = ft_itoa_base_u((unsigned short)d, 10, 1);
	if (par.ln == 3)
		*str = ft_itoa_base_u((unsigned long)d, 10, 1);
	if (par.ln == 4)
		*str = ft_itoa_base_u((unsigned long long)d, 10, 1);
	if (par.ln == 5)
		*str = ft_itoa_base_u((uintmax_t)d, 10, 1);
	if (par.ln == 6)
		*str = ft_itoa_base_u((size_t)d, 10, 1);
}

void	ft_printint_xx(char **str, t_pers par, void *d)
{
	if (par.ln == 0)
		*str = ft_itoa_base_u((unsigned int)d, 16, 1);
	if (par.ln == 1)
		*str = ft_itoa_base_u((unsigned char)d, 16, 1);
	if (par.ln == 2)
		*str = ft_itoa_base_u((unsigned short)d, 16, 1);
	if (par.ln == 3)
		*str = ft_itoa_base_u((unsigned long)d, 16, 1);
	if (par.ln == 4)
		*str = ft_itoa_base_u((unsigned long long)d, 16, 1);
	if (par.ln == 5)
		*str = ft_itoa_base_u((uintmax_t)d, 16, 1);
	if (par.ln == 6)
		*str = ft_itoa_base_u((size_t)d, 16, 1);
}

void	ft_printint_b(char **str, t_pers par, void *d)
{
	if (par.ln == 0)
		*str = ft_itoa_base_u((unsigned int)d, 2, 1);
	if (par.ln == 1)
		*str = ft_itoa_base_u((unsigned char)d, 2, 1);
	if (par.ln == 2)
		*str = ft_itoa_base_u((unsigned short)d, 2, 1);
	if (par.ln == 3)
		*str = ft_itoa_base_u((unsigned long)d, 2, 1);
	if (par.ln == 4)
		*str = ft_itoa_base_u((unsigned long long)d, 2, 1);
	if (par.ln == 5)
		*str = ft_itoa_base_u((uintmax_t)d, 2, 1);
	if (par.ln == 6)
		*str = ft_itoa_base_u((size_t)d, 2, 1);
}
