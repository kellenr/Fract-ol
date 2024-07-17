/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:14:00 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/19 22:37:26 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_fractol *fc, double zr, double zi)
{
	int		i;
	double	tmp;

	i = 0;
	while (i <= fc->iter)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + fc->j.i;
		zr = zr * zr - zi * zi + fc->j.r;
		zi = tmp;
		i++;
	}
	return (i);
}

int	ft_julia_shift(t_fractol *fc, int x, int y)
{
	fc->j.r = fc->r.min + (double)x * (fc->r.max - fc->r.min) / WIDTH;
	fc->j.i = fc->i.max + (double)y * (fc->i.min - fc->i.max) / HEIGHT;
	ft_render(fc);
	return (0);
}

int	key_julia_event(t_fractol *fc, int keysym)
{
	if (fc->set == JULIA)
	{
		if (keysym == XK_h)
			init_julia_params(fc, 0.2, 0.67);
		else if (keysym == XK_j)
			init_julia_params(fc, 0.285, 0.01);
		else if (keysym == XK_k)
			init_julia_params(fc, -0.8, 0.156);
		else if (keysym == XK_l)
			init_julia_params(fc, -0.4, 0.6);
		else if (keysym == XK_m)
			init_julia_params(fc, -0.75, 0.11);
		else if (keysym == XK_i)
			init_julia_params(fc, 0.37, -0.1);
		else if (keysym == XK_p)
			init_julia_params(fc, -0.70167, -0.3842);
		else if (keysym == XK_o)
			init_julia_params(fc, -0.835, -0.2321);
		else
			return (1);
	}
	ft_render(fc);
	return (0);
}
