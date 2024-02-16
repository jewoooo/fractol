/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:20:29 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/16 18:43:36 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	argv_error()
{
	ft_putendl_fd("Available fractal: mandelbrot or julia", 2);
	ft_putendl_fd("Please write like this.", 2);
	ft_putendl_fd("./fractol madelbrot", 2);
	ft_putendl_fd("./fractol julia", 2);
	return (1);
}

int	init_error()
{
	ft_putendl_fd("Init Error.", 2);
	return (1);
}
