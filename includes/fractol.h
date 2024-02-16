/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:03 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/16 19:40:28 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define ITER_MAX 1000
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define JULIA_X -0.70176
# define JULIA_Y -0.3842

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractal
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	char	*name;
	double	zoom;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

int		init_fractal(t_fractal *fractal);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		argv_error();
int		init_error();
int		check_argv(t_fractal *fractal, char **argv);
void	calculate_mandelbrot(t_fractal *fractal, int x, int y);
void	calculate_julia(t_fractal *fractal, int x, int y);
void	render_fractal(t_fractal *fractal);
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
int		key_event(int keycode, t_fractal *fractal);
int		mouse_event(int keycode, t_fractal *fractal);

#endif