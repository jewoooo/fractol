/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:45:43 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/17 14:15:10 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_event(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fractal->mlx, fractal->data.img);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		free(fractal->mlx);
		exit(0);
	}
	render_fractal(fractal);
	return (0);
}

int	mouse_event(int button, int x, int y, t_fractal *fractal)
{
	if (button == SCROLL_UP)
		(fractal->zoom) *= 1.05;
	else if (button == SCROLL_DOWN)
		(fractal->zoom) *= 0.95;
	render_fractal(fractal);
	return (0);	
}
