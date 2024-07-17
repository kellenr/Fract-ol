/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:05:39 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/20 14:12:50 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//window_init:
//Creates a new MLX instance, a new window and populates
//the fractol data structure with default values.
void	window_init(t_fractol *fc)
{
	fc->mlx = mlx_init();
	if (!fc->mlx)
	{
		clean_free(fc);
		ft_error();
	}
	fc->mlx_window = mlx_new_window(fc->mlx, WIDTH, HEIGHT, "Fractol");
	if (!fc->mlx_window)
	{
		clean_free(fc);
		ft_error();
	}
	ft_events(fc);
	ft_color(fc);
}

/* Initialize image, pixel and palette */
void	init_color(t_fractol *fc)
{
	fc->palette = ft_calloc(fc->iter * 4, sizeof(int));
	if (!(fc->palette))
	{
		clean_free(fc);
		ft_error();
	}
	fc->img.img = mlx_new_image(fc->mlx, WIDTH, HEIGHT);
	if (!fc->img.img)
	{
		clean_free(fc);
		ft_error();
	}
	fc->img.pix = mlx_get_data_addr(fc->img.img, &fc->img.bitp, \
			&fc->img.ln_len, &fc->img.endian);
}

/* handel events for keybord and mouse */
void	ft_events(t_fractol *fc)
{
	mlx_hook(fc->mlx_window, KeyPress, KeyPressMask, key_handler, fc);
	mlx_hook(fc->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fc);
	mlx_hook(fc->mlx_window, DestroyNotify, StructureNotifyMask, \
				close_handler, fc);
}
