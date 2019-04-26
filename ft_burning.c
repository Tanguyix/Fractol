/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 04:24:18 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/13 18:47:16 by tboissel         ###   ########.fr       */
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
	double	tmp;

	iter = 0;
	while (iter < f->iter_max)
	{
		tmp = z->real;
		z->real = (fabs(z->real) * fabs(z->real)) - (fabs(z->imag) *\
fabs(z->imag)) + c->real;
		z->imag = 2 * fabs(z->imag) * fabs(tmp) + c->imag;
		iter++;
		if (z->real * z->real + z->imag * z->imag > 4)
			break ;
	}
	return (iter);
}

void			ft_burning(t_fractol *fract)
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

void			free_three(void *c, void *z, void *p)
{
	free(c);
	free(z);
	free(p);
}
