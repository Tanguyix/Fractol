/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 05:29:52 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/13 18:37:27 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "libft/includes/libft.h"
# include <math.h>

/*
** include pour fork
*/
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# define WHEEL_UP 5
# define WHEEL_DOWN 4
# define W 0xFFFFFF

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct		s_image
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_image;

typedef struct		s_minilibx
{
	void			*m_ptr;
	void			*w;
	t_image			img;
}					t_minilibx;

typedef struct		s_complex
{
	double			imag;
	double			real;
}					t_complex;

typedef struct		s_fractol
{
	double			w_height;
	double			w_width;
	char			fr;
	int				iter_max;
	double			zoom_x;
	double			zoom_y;
	double			z_x_init;
	double			zoom_y_init;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			mv_x;
	double			mv_y;
	double			c_ju_x;
	double			c_ju_y;
	t_minilibx		*mlx;
	char			color;
	char			psychedelic;
	char			julia_mv;
}					t_fractol;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

/*
**				mlx
*/
void				ft_mlx(t_fractol *fract);
int					ft_loop_events(t_fractol *fract);
int					ft_key_events(int key, t_fractol *fract);
void				ft_change_loop(t_fractol *fract, int key);
void				ft_change_loop_2(t_fractol *fract, int key);
void				ft_which_fractol(t_fractol *fract);
void				ft_change_fractol(t_fractol *fract);
void				ft_reset(t_fractol *fract, int key);

/*
**				Zoom
*/
int					ft_zoom(int key, int x, int y, t_fractol *fract);
void				ft_handle_zoom(t_fractol *fract);

/*
**				Usage et fin programme
*/
void				ft_too_many_fractals(void);
int					ft_exit(void);
void				ft_usage(void);
void				ft_tutorial(t_fractol *fract);
void				ft_compare(t_fractol *fract, char *av);
void				free_three(void *c, void *z, void *p);

/*
**				Initialisation de la structure
*/
void				ft_init_fractol(t_fractol *fract);
void				ft_init_mandel(t_fractol *fract);
void				ft_init_julia(t_fractol *fract);
void				ft_init_burning(t_fractol *fract);
void				ft_init_tricorn(t_fractol *fract);

/*
**				Couleurs
*/
void				ft_colors(t_fractol *frac, int iter, int index);

/*
**				Fonctions de calcul et d'affichage des fractales
*/
void				ft_mandel(t_fractol *fract);

void				ft_julia(t_fractol *fract);
int					ft_c_julia(int x, int y, t_fractol *fract);

void				ft_burning(t_fractol *fract);

void				ft_tricorn(t_fractol *fract);

int					rand_a_b(int a, int b);

#endif
