/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 05:29:23 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/13 18:02:37 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
{
	t_fractol	*fract;
	int			pid;

	if (!(fract = malloc(sizeof(t_fractol))))
		return (0);
	ft_init_fractol(fract);
	if (ac > 10)
		ft_too_many_fractals();
	if (ac > 1)
	{
		ft_compare(fract, av[1]);
		if (ac >= 3 && ac <= 10)
		{
			pid = fork();
			if (pid == 0)
				execvp("./fractol", &av[1]);
			else
				ft_mlx(fract);
		}
		ft_mlx(fract);
	}
	else
		ft_usage();
}
