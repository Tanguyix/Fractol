/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:16:31 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/13 18:12:50 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_zoom(int key, int x, int y, t_fractol *f)
{
	double	temp;

	if (key == WHEEL_UP && (f->zoom_x *= 1.05))
	{
		f->x1 += (f->z_x_init / f->zoom_x) * (x - f->w_width / 2) / f->w_width;
		f->x2 += (f->z_x_init / f->zoom_x) * (x - f->w_width / 2) / f->w_width;
		f->y1 += (f->zoom_y_init / f->zoom_y) *
(y - f->w_height / 2) / f->w_height;
		f->y2 += (f->zoom_y_init / f->zoom_y) *
(y - f->w_height / 2) / f->w_height;
		f->zoom_y *= 1.05;
	}
	if (key == WHEEL_DOWN && (f->zoom_x *= 0.95))
	{
		f->x1 -= (f->z_x_init / f->zoom_x) *
((f->w_width / 2) - x) / f->w_width;
		f->x2 -= (f->z_x_init / f->zoom_x) *
((f->w_width / 2) - x) / f->w_width;
		f->y1 -= (f->z_x_init / f->zoom_x) *
((f->w_height / 2) - y) / f->w_height;
		f->y2 -= (f->z_x_init / f->zoom_x) *
((f->w_height / 2) - y) / f->w_height;
		f->zoom_y *= 0.95;
	}
	return (0);
}

void		ft_handle_zoom(t_fractol *f)
{
	if (!f->zoom_x || !f->zoom_y)
	{
		f->zoom_x = (f->w_width) / (f->x2 - f->x1);
		f->zoom_y = f->w_height / (f->y2 - f->y1);
		if (f->fr == 't')
		{
			f->zoom_x /= 2;
			f->zoom_y /= 2;
		}
		f->z_x_init = f->zoom_x;
		f->zoom_y_init = f->zoom_y;
	}
	if (f->mv_x || f->mv_y)
	{
		f->x1 += (f->z_x_init / f->zoom_x) * f->mv_x;
		f->x2 += (f->z_x_init / f->zoom_x) * f->mv_x;
		f->y1 += (f->zoom_y_init / f->zoom_y) * f->mv_y;
		f->y2 += (f->zoom_y_init / f->zoom_y) * f->mv_y;
	}
}
