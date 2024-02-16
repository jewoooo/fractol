/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:02:37 by jewlee            #+#    #+#             */
/*   Updated: 2024/02/16 18:29:27 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (unscaled_num - old_min) * (new_max - new_min) / (old_max - old_min) + new_min;
}
