/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:45:43 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/16 19:49:17 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_event(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_image(fractal->mlx, fractal->data.img);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		free(fractal->mlx);
		exit(0);
	}
	return (0);
}

int	mouse_event(int keycode, t_fractal *fractal)
{
	if (keycode == 4)
		(fractal->zoom) *= 1.5;
	else if (keycode == 5)
		(fractal->zoom) *= 0.5;
	render_fractal(fractal);
	return (0);	
}
