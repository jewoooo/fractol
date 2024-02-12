/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:30:35 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/12 17:49:18 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit(0);
	else
		return (0);
	return (0);
}

int	mouse_hook(int mouse_code, t_fractal *fractal)
{
	
}