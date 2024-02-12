/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:33:13 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/12 17:30:22 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_putendl_fd("Example: ./fractol <fractal>", 1);
		ft_putendl_fd("fractal: mandelbrot, julia", 1);
		return (0);
	}
	if (init_fractal(fractal) == 0)
		return (0);
	init_mlx(fractal);
	mlx_key_hook
	mlx_mouse_hook
	mlx_hook
	// 훅 (키, 마우스) 등록
	// fractal 그리기
	// loop(mlx);
	return (0);
}
 