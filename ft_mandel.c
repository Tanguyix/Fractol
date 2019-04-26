/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:53:24 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/13 18:40:51 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_loop(t_complex *c, t_complex *z, t_point *p, t_fractol *f)
{
	c->real = (p->x / f->zoom_x) + f->x1;
	c->imag = (p->y / f->zoom_y) + f->y1;
	z->real = 0;
	z->imag = 0;
}

static int		iner_calc(t_complex *z, t_complex *c, int iter, t_fractol *f)
{
	double		tmp;

	iter = 0;
	while (iter < f->iter_max)
	{
		tmp = z->real;
		z->real = (z->real * z->real) - (z->imag * z->imag) + c->real;
		z->imag = 2 * z->imag * tmp + c->imag;
		iter++;
		if (z->real * z->real + z->imag * z->imag > 4)
			break ;
	}
	return (iter);
}

void			ft_mandel(t_fractol *f)
{
	t_point		*point;
	int			iter;
	t_complex	*c;
	t_complex	*z;

	ft_handle_zoom(f);
	point = malloc(sizeof(t_point));
	c = malloc(sizeof(t_complex));
	z = malloc(sizeof(t_complex));
	if (!c || !z || !(point))
		exit(0);
	ft_bzero(point, sizeof(t_point));
	while (++point->x < f->w_width && (point->y = -1))
	{
		while (++point->y < f->w_height)
		{
			init_loop(c, z, point, f);
			iter = iner_calc(z, c, iter, f);
			if (f->color != 10 && iter < f->iter_max)
				ft_colors(f, iter, (int)(point->x + point->y * f->w_width));
			else if (f->color == 10 && iter >= f->iter_max)
				ft_colors(f, iter, (int)(point->x + point->y * f->w_width));
		}
	}
	free_three(c, z, point);
}
