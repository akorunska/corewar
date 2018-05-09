/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:52:49 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/30 14:30:19 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		check_max_int(long int new_res)
{
	long int max_int;

	max_int = 2147483647;
	if (new_res > max_int)
	{
		return (1);
	}
	return (0);
}

static	int		check_sign(char ch)
{
	if (ch == '-')
	{
		return (-1);
	}
	else if (ch == '+')
	{
		return (1);
	}
	return (0);
}

static	int		is_whitespace(char ch)
{
	if (ch == ' ' || (ch >= 9 && ch <= 13))
		return (1);
	return (0);
}

int				ft_atoi(char *str)
{
	int i;
	int digits;
	int sign;
	int res;

	i = 0;
	res = 0;
	digits = 0;
	while (is_whitespace(str[i]))
		i++;
	sign = check_sign(str[i]);
	if (sign != 0)
		i++;
	else
		sign = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!check_max_int(res * 10 + (str[i] - '0')))
			res = res * 10 + (str[i] - '0');
		i++;
		digits++;
	}
	if (digits >= 20)
		return (sign == -1) ? (0) : (-1);
	return (res * sign);
}
