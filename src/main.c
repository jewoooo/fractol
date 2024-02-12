/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:55:55 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/12 20:18:46 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#define WIDTH
#define HEIGHT
#define KEY_ESC		53
#define SCROLL_UP	4
#define SCROLL_DOWN	5

typedef struct	s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	
}	t_fractal;

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_putendl_fd("Can you type only 1 argument after ./fractol?", 1);
		ft_putenel_fd("For example: ./fractol mandelbrot", 1);
		ft_putendl_fd("Available argument: mandelbrot, julia", 1);
		return (1);
	}

}
