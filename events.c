/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 06:45:39 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/18 13:24:44 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_events(int key, t_fractol *fract)
{
	if (key == 15 || key == 31)
		ft_reset(fract, key);
	if (key == 48)
		ft_change_fractol(fract);
	if (key == 53)
		ft_exit();
	if (key == 13 || key == 0 || key == 1 || key == 2 || key == 49 ||
(key >= 123 && key <= 126))
		ft_change_loop(fract, key);
	if (key == 69)
		fract->iter_max += 10;
	else if (key >= 82 && key <= 92)
		fract->color = (key % 82);
	if ((key >= 82 && key <= 92) && fract->psychedelic)
		fract->psychedelic--;
	if (key == 35)
		fract->psychedelic = (fract->psychedelic ? 0 : 1);
	return (0);
}

int		ft_loop_events(t_fractol *fract)
{
	if (fract->fr == 'B')
		return (0);
	if (fract->psychedelic)
	{
		ft_change_fractol(fract);
		if (fract->fr == 'j')
			ft_c_julia(rand_a_b(-800, 800), rand_a_b(-800, 800), fract);
		fract->color += (fract->color == 8 ? 2 : 1);
		if (fract->color == 11)
			fract->color = 0;
	}
	ft_bzero(fract->mlx->img.data, 4 * fract->w_height * fract->w_width + 1);
	if (fract->fr == 'b')
		ft_burning(fract);
	else if (fract->fr == 'm')
		ft_mandel(fract);
	else if (fract->fr == 'j')
		ft_julia(fract);
	else if (fract->fr == 't')
		ft_tricorn(fract);
	mlx_put_image_to_window(fract->mlx->m_ptr, fract->mlx->w,
fract->mlx->img.img_ptr, 0, 0);
	return (0);
}

void	ft_change_loop(t_fractol *fract, int key)
{
	if (key == 49)
	{
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->psychedelic = 0;
	}
	else if (key == 13 || key == 126)
	{
		if (fract->mv_y < 0)
			fract->mv_y = 0;
		else
			fract->mv_y += 0.02;
	}
	else if (key == 1 || key == 125)
	{
		if (fract->mv_y > 0)
			fract->mv_y = 0;
		else
			fract->mv_y -= 0.02;
	}
	else if (key == 0 || key == 123 || key == 2 || key == 124)
		ft_change_loop_2(fract, key);
}

void	ft_change_loop_2(t_fractol *fract, int key)
{
	if (key == 0 || key == 123)
	{
		if (fract->mv_x < 0)
			fract->mv_x = 0;
		else
			fract->mv_x += 0.02;
	}
	else if (key == 2 || key == 124)
	{
		if (fract->mv_x > 0)
			fract->mv_x = 0;
		else
			fract->mv_x -= 0.02;
	}
}

void	ft_change_fractol(t_fractol *fract)
{
	fract->zoom_x = 0;
	fract->zoom_y = 0;
	if (fract->fr == 'j')
	{
		ft_init_mandel(fract);
		fract->fr = 'm';
	}
	else if (fract->fr == 'm')
	{
		ft_init_tricorn(fract);
		fract->fr = 't';
	}
	else if (fract->fr == 't')
	{
		ft_init_burning(fract);
		fract->fr = 'b';
	}
	else if (fract->fr == 'b')
	{
		ft_init_julia(fract);
		fract->fr = 'j';
	}
}
