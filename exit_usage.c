/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 06:41:22 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/13 19:30:47 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_exit(void)
{
	exit(0);
}

void		ft_usage(void)
{
	ft_putstr("Usage: ./fractol <fractals name separated by spaces>\n");
	ft_putstr("fractals : julia, mandelbrot, burningship, tricorn\n");
	ft_putstr("type tutorial to get the commands\n");
}

void		ft_too_many_fractals(void)
{
	ft_putstr("Warning : 10 fractals maximum\n\
Only the first one will be displayed");
}

void		ft_compare(t_fractol *fract, char *av)
{
	if (!ft_strcmp(av, "tutorial"))
		fract->fr = 'T';
	else if (!ft_strcmp(av, "julia"))
		fract->fr = 'j';
	else if (!ft_strcmp(av, "mandelbrot"))
		fract->fr = 'm';
	else if (!ft_strcmp(av, "burningship"))
		fract->fr = 'b';
	else if (!ft_strcmp(av, "tricorn"))
		fract->fr = 't';
	else
	{
		ft_usage();
		exit(0);
	}
}

void		ft_reset(t_fractol *fract, int key)
{
	if (key == 15)
	{
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->zoom_x = 0;
		fract->zoom_y = 0;
		fract->iter_max = 50;
		ft_which_fractol(fract);
	}
	else if (key == 31)
	{
		if (fract->julia_mv)
			fract->julia_mv = 0;
		else
			fract->julia_mv = 1;
	}
}
