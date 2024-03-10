/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:03 by jewlee            #+#    #+#             */
/*   Updated: 2024/03/11 00:26:48 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 800
# define HEIGHT 800
# define ITER_MAX 42

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC 53

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
	double	julia_x;
	double	julia_y;
	double	zoom;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

int		init_fractal(t_fractal *f);
int		init_julia(t_fractal *f, char **argv);

int		free_mlx(t_fractal *f);
int		argv_error(void);
int		init_error(void);

int		check_fractal(t_fractal *fractal, int argc, char **argv);
int		check_argv(char **argv);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	calculate_mandelbrot(t_fractal *fractal, int x, int y);
void	calculate_julia(t_fractal *fractal, int x, int y);
void	render_fractal(t_fractal *fractal);

int		key_event(int keycode, t_fractal *fractal);
int		mouse_event(int button, int x, int y, t_fractal *fractal);

double	ft_atodbl(char *s);
double	map(double unscaled_num, double old_max, double new_min,
			double new_max);

#endif
