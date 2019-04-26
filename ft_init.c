/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 03:15:57 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/13 14:58:55 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_init_fractol(t_fractol *fract)
{
	fract->julia_mv = 1;
	fract->w_width = 1200;
	fract->w_height = 900;
	fract->iter_max = 50;
	fract->mv_x = 0;
	fract->mv_y = 0;
	fract->color = 0;
	fract->zoom_x = 0;
	fract->zoom_y = 0;
	fract->psychedelic = 0;
	if (fract->fr == 's')
		fract->w_width = 800;
}

void				ft_init_mandel(t_fractol *fract)
{
	fract->x1 = -2.1;
	fract->x2 = 0.6;
	fract->y1 = -1.2;
	fract->y2 = 1.2;
}

void				ft_init_julia(t_fractol *fract)
{
	fract->x1 = -1;
	fract->x2 = 1;
	fract->y1 = -1.2;
	fract->y2 = 1.2;
	fract->c_ju_x = 0.35;
	fract->c_ju_y = -0.150;
}

void				ft_init_burning(t_fractol *fract)
{
	fract->x1 = -2.1;
	fract->x2 = 0.6;
	fract->y1 = -2;
	fract->y2 = 1.2;
}

void				ft_init_tricorn(t_fractol *fract)
{
	fract->x1 = -2.84;
	fract->x2 = -0.14;
	fract->y1 = -2.26;
	fract->y2 = 0.14;
}
