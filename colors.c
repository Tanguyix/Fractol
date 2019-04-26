/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 03:24:24 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/14 11:54:09 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_colors(t_fractol *fract, int iter, int index)
{
	if (fract->color == 0)
		fract->mlx->img.data[index] = (iter) * 0x000010;
	else if (fract->color == 1)
		fract->mlx->img.data[index] = (iter) * 0x000900;
	else if (fract->color == 2)
		fract->mlx->img.data[index] = (iter) * 0x0c0000;
	else if (fract->color == 3)
		fract->mlx->img.data[index] = (iter) * 0x0f0700;
	else if (fract->color == 4)
		fract->mlx->img.data[index] = (iter) * 0x060606;
	else if (fract->color == 5)
		fract->mlx->img.data[index] = ((RGB(20 * (cos(iter) + 1),
			127.5 * (sin(iter) + 1),
			60 * (1 - cos(iter)))));
	else if (fract->color == 6)
		fract->mlx->img.data[index] = (iter) * 0x202020;
	else if (fract->color == 7)
		fract->mlx->img.data[index] = ((RGB(
			127.5 * (cos(iter) + 1),
			127.5 * (sin(iter) + 1),
			127.5 * (1 - cos(iter)))));
	else if (fract->color == 9)
		fract->mlx->img.data[index] = (iter) * rand_a_b(0, 0xb0b0b0);
	else if (fract->color == 10)
		fract->mlx->img.data[index] = (iter) * rand_a_b(0, 0xb0b0b0);
}
