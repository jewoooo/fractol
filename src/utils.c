/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:02:37 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/10 23:59:17 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	find_dot(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.')
			return (i);
		i++;
	}
	return (-1);
}

static int	init_flag(char *s)
{
	int	flag;

	flag = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-')
	{
		flag = 1;
		s++;
	}
	else if (*s == '+')
		s++;
	return (flag);
}

double	ft_atodbl(char *s)
{
	int		i;
	int		flag;
	int		digit;
	double	res;

	flag = init_flag(s);
	i = -1;
	res = 0;
	while (s[++i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (find_dot(s) == -1 || find_dot(s) > i)
				res = res * 10 + (double)digit;
			else
				res = res + ((double)digit / pow(10, i - find_dot(s)));
		}
	}
	if (flag == 1)
		res *= (-1);
	return (res);
}

double	map(double unscaled_num, double old_max, double new_min, double new_max)
{
	double	old_ratio;
	double	new_num;

	old_ratio = (unscaled_num - 0) / (old_max - 0);
	new_num = old_ratio * (new_max - new_min) + new_min;
	return (new_num);
}
