/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:55:21 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/19 18:44:01 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractol *fc, int argc, char **argv)
{
	if (argc == 2)
	{
		init_data(fc);
		julia_opt();
	}
	else if (argc == 4)
		init_julia_params(fc, ft_atof(argv[2]), ft_atof(argv[3]));
	else
	{
		ft_printf("Julia set requires 0 or 2 parameters more. \n");
		exit(EXIT_FAILURE);
	}
}

void	init_set(t_fractol *fc, int argc, char **argv)
{
	if (argc == 2)
		init_data(fc);
	else if (argc == 3)
	{
		is_string_numeric(argv[2]);
		init_set_params(fc, ft_atoi(argv[2]));
	}
	else
	{
		ft_printf("Mandelbrot set requires one parameter for iterations.\n");
		exit(EXIT_FAILURE);
	}
}

void	init_data(t_fractol *fc)
{
	if (fc->set == JULIA)
	{
		fc->j.r = -0.766667;
		fc->j.i = -0.090000;
		fc->r.min = -2.0;
		fc->i.min = -1.5;
		fc->r.max = 2.0;
		fc->i.max = 1.5;
		fc->esc = 4.0;
		fc->iter = MAX_ITER;
	}
	else
	{
		fc->esc = 4.0;
		fc->r.min = -2.0;
		fc->i.min = -1.5;
		fc->r.max = 1.0;
		fc->i.max = 1.5;
		fc->iter = MAX_ITER;
	}
}

void	init_julia_params(t_fractol *fc, double j_r, double j_i)
{
	if ((j_r > 2.0 || j_r < -2.0) || (j_i > 2.0 || j_i < -2.0))
	{
		ft_printf(P_R"Error: Julia set parameters out of range\n\n" RT);
		julia_opt();
		exit(EXIT_FAILURE);
	}
	fc->j.r = j_r;
	fc->j.i = j_i;
	fc->r.min = -2.0;
	fc->i.min = -1.5;
	fc->r.max = 2.0;
	fc->i.max = 1.5;
	fc->esc = 4.0;
	fc->iter = MAX_ITER;
}

void	init_set_params(t_fractol *fc, int i)
{
	fc->iter = i;
	fc->esc = 4.0;
	fc->r.min = -2.0;
	fc->i.min = -1.5;
	fc->r.max = 1.0;
	fc->i.max = 1.5;
}
