/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:20:48 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/12 17:29:37 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	init_fractal(t_fractal *fractal)
{
	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (fractal == NULL)
		return (0);
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFF0000;
	fractal->zoom = 300;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->max_iterations = 42;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractol");
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel,
			&fractal->line_length,
			&fractal->endian);
}
