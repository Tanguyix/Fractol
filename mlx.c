/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 06:31:22 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/13 18:15:45 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_mlx(t_fractol *f)
{
	if (f->fr == 'T')
		ft_tutorial(f);
	if (!(f->mlx = malloc(sizeof(t_minilibx))))
		exit(0);
	f->mlx->m_ptr = mlx_init();
	f->mlx->w = mlx_new_window(f->mlx->m_ptr, f->w_width, f->w_height,
"FRACT'OL");
	f->mlx->img.img_ptr = mlx_new_image(f->mlx->m_ptr, f->w_width, f->w_height);
	f->mlx->img.data = (int *)mlx_get_data_addr(f->mlx->img.img_ptr,
&f->mlx->img.bpp, &f->mlx->img.size_l, &f->mlx->img.endian);
	ft_which_fractol(f);
	mlx_put_image_to_window(f->mlx->m_ptr, f->mlx->w,
f->mlx->img.img_ptr, 0, 0);
	mlx_key_hook(f->mlx->w, ft_key_events, f);
	mlx_loop_hook(f->mlx->m_ptr, ft_loop_events, f);
	mlx_mouse_hook(f->mlx->w, ft_zoom, f);
	mlx_hook(f->mlx->w, 17, 0, ft_exit, 0);
	mlx_hook(f->mlx->w, 6, 1L << 6, ft_c_julia, f);
	mlx_loop(f->mlx->m_ptr);
}

void				ft_which_fractol(t_fractol *fract)
{
	if (fract->fr == 'm')
	{
		ft_init_mandel(fract);
		ft_mandel(fract);
	}
	else if (fract->fr == 'j')
	{
		ft_init_julia(fract);
		ft_julia(fract);
	}
	else if (fract->fr == 'b')
	{
		ft_init_burning(fract);
		ft_burning(fract);
		mlx_put_image_to_window(fract->mlx->m_ptr, fract->mlx->w,
fract->mlx->img.img_ptr, 0, 0);
	}
	else if (fract->fr == 't')
	{
		ft_init_tricorn(fract);
		ft_tricorn(fract);
	}
	else
		ft_exit();
}
