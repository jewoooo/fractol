/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:18:49 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/19 12:26:56 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_fractal(t_fractal *fractal, int argc, char **argv)
{
	if ((ft_strncmp(argv[1], "mandelbrot", 10) == 0 && argc == 2)
		|| (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4))
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
		while (argv[i][++j] != '\0')
		{
			if ((argv[i][j] >= 'A' && argv[i][j] <= 'Z')
				|| (argv[i][j] >= 'a' && argv[i][j] <= 'z'))
				return (0);
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				digit_flag = 1;
		}
		if (digit_flag == 0)
			return (0);
	}
	return (1);
}
