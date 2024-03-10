/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:45:43 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/11 00:23:15 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_event(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		free_mlx(fractal);
		exit(0);
	}
	return (0);
}

int	mouse_event(int button, int x, int y, t_fractal *fractal)
{
	x *= 1;
	y *= 1;
	if (button == SCROLL_UP)
		fractal->zoom *= 1.2;
	else if (button == SCROLL_DOWN)
		(fractal->zoom) *= 0.8;
	render_fractal(fractal);
	return (0);
}
