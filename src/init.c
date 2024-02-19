/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:43:44 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/19 12:24:53 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	init_julia(t_fractal *f, char **argv)
{
	if (check_argv(argv) == 0)
		return (0);
	f->julia_x = ft_atodbl(argv[2]);
	f->julia_y = ft_atodbl(argv[3]);
	return (1);
}

int	init_fractal(t_fractal *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		return (0);
	f->mlx_win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	if (f->mlx_win == NULL)
	{
		free(f->mlx);
		return (0);
	}
	f->data.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (f->data.img == NULL)
	{
		free(f->mlx);
		mlx_destroy_window(f->mlx, f->mlx_win);
		return (0);
	}
	f->data.addr = mlx_get_data_addr(f->data.img, &(f->data.bits_per_pixel),
			&(f->data.line_length), &(f->data.endian));
	if (f->data.addr == NULL)
		return (free_mlx(f));
	f->zoom = 1;
	return (1);
}
