/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:25:46 by keramos-          #+#    #+#             */
/*   Updated: 2024/07/01 16:31:13 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color(t_imgs *img, int x, int y, int color)
{
	int	index;

	index = (y * img->ln_len) + (x * (img->bitp / 8));
	*(unsigned int *)(img->pix + index) = color;
}

void	recoloring_img(t_fractol *fc)
{
	if (fc->mlx && fc->img.img)
	{
		mlx_destroy_image(fc->mlx, fc->img.img);
	}
	if (fc->palette)
		free(fc->palette);
	if (fc->img.pix)
		fc->img.pix = NULL;
	init_color(fc);
}

void	ft_color(t_fractol *fc)
{
	int	tmp;

	fc->color_p = (fc->color_p + 1) % 6;
	recoloring_img(fc);
	if (fc->color == 0x000000)
		tmp = 0xC896DC;
	else
		tmp = fc->color;
	if (fc->color_p == 0)
		set_color_one(fc, tmp);
	else if (fc->color_p == 1)
		set_color_one(fc, 0xFFB347);
	else if (fc->color_p == 2)
		set_color_one(fc, 0x0000FF);
	else if (fc->color_p == 3)
		set_color_two(fc, 0xFFB347, 0x0000FF);
	else if (fc->color_p == 4)
		set_color_two(fc, 0x2E0854, 0xE6E6FA);
	else if (fc->color_p == 5)
		set_color_rainbow(fc, fc->palette);
}

/*  function is essential for creating smooth transitions between two colors.
*  This process is known as color interpolation or gradient generation.*/
int	interpolate(int start, int end, double pos)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((start >> 16) & 0xFF);
	start_rgb[1] = ((start >> 8) & 0xFF);
	start_rgb[2] = ((start >> 0) & 0xFF);
	end_rgb[0] = ((end >> 16) & 0xFF);
	end_rgb[1] = ((end >> 8) & 0xFF);
	end_rgb[2] = ((end >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * pos + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * pos + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * pos + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}
