/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 02:52:16 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/14 14:29:28 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		iner_calc(t_complex *z, t_complex *c, int iter, t_fractol *f)
{
	double	tmp;

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

static void		init_loop(t_complex *c, t_complex *z, t_point *p, t_fractol *f)
{
	z->real = (p->x / f->zoom_x) + f->x1;
	z->imag = (p->y / f->zoom_y) + f->y1;
	c->real = f->c_ju_x;
	c->imag = f->c_ju_y;
}

void			ft_julia(t_fractol *fract)
{
	t_point		*p;
	int			iter;
	t_complex	*c;
	t_complex	*z;

	p = malloc(sizeof(t_point));
	c = malloc(sizeof(t_complex));
	z = malloc(sizeof(t_complex));
	if (!c || !z || !(p))
		exit(0);
	ft_bzero(p, sizeof(t_point));
	ft_handle_zoom(fract);
	while (++p->x < fract->w_width && (p->y = -1))
	{
		while (++p->y < fract->w_height)
		{
			init_loop(c, z, p, fract);
			iter = iner_calc(z, c, iter, fract);
			if (fract->color != 10 && iter < fract->iter_max)
				ft_colors(fract, iter, (int)(p->x + p->y * fract->w_width));
			else if (fract->color == 10 && iter >= fract->iter_max)
				ft_colors(fract, iter, (int)(p->x + p->y * fract->w_width));
		}
	}
	free_three(c, z, p);
}

int				ft_c_julia(int x, int y, t_fractol *fract)
{
	if (fract->julia_mv)
	{
		fract->c_ju_x = 0.002 * x;
		fract->c_ju_y = 0.002 * y;
	}
	return (0);
}

int				rand_a_b(int a, int b)
{
	return (rand() % (b - a) + a);
}
