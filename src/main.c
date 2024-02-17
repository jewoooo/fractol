/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:57:33 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/17 14:10:48 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_data(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
}

int	init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		return (0);
	fractal->mlx_win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_win == NULL)
	{
		free(fractal->mlx);
		return (0);
	}
	fractal->data.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->data.img == NULL)
	{
		free(fractal->mlx);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		return (0);
	}
	fractal->data.addr = mlx_get_data_addr(fractal->data.img, &(fractal->data.bits_per_pixel)
		, &(fractal->data.line_length), &(fractal->data.endian));
	init_data(fractal);
	return (1);
}

/*
 * mouse wheel -> zoom
 * ESC -> quit
 * */

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc != 2)
		return (argv_error());
	if (check_argv(&fractal, argv) == 0)
		return (argv_error());
	if (init_fractal(&fractal) == 0)
		return (init_error());
	render_fractal(&fractal);
	mlx_key_hook(fractal.mlx_win, key_event, &fractal);
	mlx_mouse_hook(fractal.mlx_win, mouse_event, &fractal);
	mlx_loop(fractal.mlx);
}
