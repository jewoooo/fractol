/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:13:27 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/11 00:09:13 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	calculate_mandelbrot(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;
	int			color;

	z.x = 0;
	z.y = 0;
	c.x = map((double)x, WIDTH, -2, 2) * fractal->zoom;
	c.y = map((double)y, HEIGHT, 2, -2) * fractal->zoom;
	i = 0;
	while (i < ITER_MAX && (z.x * z.x + z.y * z.y <= 4))
	{
		tmp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = (2 * z.x * z.y) + c.y;
		z.x = tmp;
		i++;
	}
	if (i == ITER_MAX)
		my_mlx_pixel_put(&(fractal->data), x, y, BLACK);
	else
	{
		color = map(i, ITER_MAX, BLACK, WHITE);
		my_mlx_pixel_put(&(fractal->data), x, y, color);
	}
}

void	calculate_julia(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;
	int			color;

	z.x = map((double)x, WIDTH, -2, 2) * fractal->zoom;
	z.y = map((double)y, HEIGHT, 2, -2) * fractal->zoom;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	i = 0;
	while (i < ITER_MAX && (z.x * z.x + z.y * z.y <= 4))
	{
		tmp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = (2 * z.x * z.y) + c.y;
		z.x = tmp;
		i++;
	}
	if (i == ITER_MAX)
		my_mlx_pixel_put(&(fractal->data), x, y, WHITE);
	else
	{
		color = map(i, ITER_MAX, BLACK, WHITE);
		my_mlx_pixel_put(&(fractal->data), x, y, color);
	}
}

void	render_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
				calculate_mandelbrot(fractal, x, y);
			else if (ft_strncmp(fractal->name, "julia", 5) == 0)
				calculate_julia(fractal, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->data.img, 0, 0);
}
