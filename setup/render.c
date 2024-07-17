/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:40:09 by keramos-          #+#    #+#             */
/*   Updated: 2024/07/01 16:31:20 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handel_set(t_fractol *fc, double x, double y)
{
	int	color;

	color = 0;
	if (fc->set == MANDELBROT)
		color = ft_mandelbrot(fc, x, y);
	else if (fc->set == JULIA)
		color = ft_julia(fc, x, y);
	else if (fc->set == TRICORN)
		color = ft_tricorn(fc, x, y);
	else if (fc->set == NOVA)
		color = ft_nova(fc, x, y);
	if (color < 0)
		color = 0;
	else if (color >= fc->iter)
		color = fc->iter - 1;
	return (color);
}

void	ft_render(t_fractol *fc)
{
	int			x;
	int			y;
	t_complex	f;
	int			nb;

	mlx_clear_window(fc->mlx, fc->mlx_window);
	y = 0;
	while (++y < HEIGHT)
	{
		x = 0;
		while (++x < WIDTH)
		{
			f.r = fc->r.min + (double)x * (fc->r.max - fc->r.min) / WIDTH;
			f.i = fc->i.max + (double)y * (fc->i.min - fc->i.max) / HEIGHT;
			nb = handel_set(fc, f.r, f.i);
			set_color(&fc->img, x, y, fc->palette[nb]);
		}
	}
	mlx_put_image_to_window(fc->mlx, fc->mlx_window, fc->img.img, 0, 0);
}
