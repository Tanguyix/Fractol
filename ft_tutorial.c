/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tutorial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:33:21 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/13 18:48:24 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_tutorial_2(t_fractol *f)
{
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 90, W, "Reset fractal");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 110, W, "Tab");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 110, W, "Next fractal");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 130, W, "P");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 130, W, "Psychedelic mod");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 150, W, "Mouse mouvements");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 150, W,
"Change Julia Parameters");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 170, W, "O");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 170, W,
"Julia mouvements On/Off");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 190, W, "ESC");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 190, W, "End program");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 210, W, "+ / -");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 210, W,
"increase/decrease iterations");
	mlx_key_hook(f->mlx->w, ft_key_events, f);
	mlx_hook(f->mlx->w, 17, 0, ft_exit, 0);
	mlx_loop(f->mlx->m_ptr);
}

void			ft_tutorial(t_fractol *f)
{
	if (!(f->mlx = malloc(sizeof(t_minilibx))))
		exit(0);
	f->mlx->m_ptr = mlx_init();
	f->mlx->w = mlx_new_window(f->mlx->m_ptr, 520, 240, "Tutorial");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 10, W, "WASD or arrows");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 10, W, "Move fractal");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 30, W, "Spacebar");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 30, W, "Stop movements");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 70, W, "0-9");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 70, W, "Color Palettes");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 50, W, "Mouse Wheel");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 240, 50, W, "Zoom in and out");
	mlx_string_put(f->mlx->m_ptr, f->mlx->w, 10, 90, W, "R");
	ft_tutorial_2(f);
	mlx_key_hook(f->mlx->w, ft_key_events, f);
	mlx_hook(f->mlx->w, 17, 0, ft_exit, 0);
	mlx_loop(f->mlx->m_ptr);
}
