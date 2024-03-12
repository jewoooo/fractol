/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:57:33 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/12 14:03:35 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc < 2 || argc > 4) || argc == 3)
		return (argv_error());
	if (check_fractal(&fractal, argc, argv) == 0)
		return (argv_error());
	if (init_fractal(&fractal) == 0)
		return (init_error());
	render_fractal(&fractal);
	mlx_key_hook(fractal.mlx_win, key_event, &fractal);
	mlx_mouse_hook(fractal.mlx_win, mouse_event, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
