/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:17:17 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/16 18:29:32 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_argv(t_fractal *fractal, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0
		|| ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fractal->name = argv[1];
		return (1);
	}
	return (0);
}
