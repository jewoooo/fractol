/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:18:49 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/11 05:40:05 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_fractal(t_fractal *fractal, int argc, char **argv)
{
	if ((argc == 2 && ft_strlen(argv[1]) == 10
			&& ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		|| (argc == 4 && ft_strlen(argv[1]) == 5
			&& ft_strncmp(argv[1], "julia", 5) == 0))
	{
		fractal->name = argv[1];
		if (ft_strncmp(fractal->name, "julia", 5) == 0)
		{
			if (init_julia(fractal, argv) == 0)
				return (0);
		}
		return (1);
	}
	return (0);
}

static int	cnt_plus_minus(char *s)
{
	int	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*s == '+')
			cnt++;
		else if (*s == '-')
			cnt++;
		s++;
	}
	return (cnt);
}

static int	check_str(char *s)
{
	int	i;
	int	cnt;

	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
		s++;
	i = -1;
	cnt = 0;
	while (s[++i] != '\0')
	{
		if (ft_isalpha(s[i]) == 1)
			return (1);
		if ((ft_isdigit(s[i]) == 0 && s[i] != '.')
			&& ft_isdigit(s[i]) == 0)
			return (1);
		if (s[i] == '.')
			cnt++;
	}
	if (cnt > 1)
		return (1);
	return (0);
}

int	check_argv(char **argv)
{
	int	i;
	int	j;
	int	digit_flag;

	i = 1;
	while (argv[++i] != NULL)
	{
		j = -1;
		digit_flag = 0;
		if (cnt_plus_minus(argv[i]) > 1)
			return (0);
		if (check_str(argv[i]) == 1)
			return (0);
		while (argv[i][++j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 1)
				digit_flag = 1;
		}
		if (digit_flag == 0)
			return (0);
	}
	return (1);
}
