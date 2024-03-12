/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:20:29 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/12 14:02:59 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	free_mlx(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->data.img);
	mlx_destroy_window(f->mlx, f->mlx_win);
	exit(1);
	return (0);
}

int	argv_error(void)
{
	ft_putendl_fd("Available fractal: mandelbrot or julia", 2);
	ft_putendl_fd("Please write like this.", 2);
	ft_putendl_fd("./fractol mandelbrot", 2);
	ft_putendl_fd("./fractol julia <x> <y>", 2);
	return (1);
}

int	init_error(void)
{
	ft_putendl_fd("Init Error.", 2);
	return (1);
}
