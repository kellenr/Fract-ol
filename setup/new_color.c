/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:43:26 by keramos-          #+#    #+#             */
/*   Updated: 2024/07/01 16:31:17 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* we just work with one color */
void	set_color_one(t_fractol *fc, int color)
{
	int		start;
	double	pos;
	int		i;
	int		j;

	i = 0;
	start = 0x000000;
	while (i <= fc->iter)
	{
		j = 0;
		while (j <= fc->iter / 2)
		{
			pos = (double)j / (fc->iter / 2);
			fc->palette[i + j] = interpolate(start, color, pos);
			j++;
		}
		start = color;
		color = 0xC896DC;
		i += j;
	}
	fc->palette[fc->iter - 1] = 0;
}

/* we work with two color */
void	set_color_two(t_fractol *fc, int color1, int color2)
{
	int		i;
	int		j;
	double	pos;

	i = 0;
	while (i < fc->iter)
	{
		j = 0;
		while (j < fc->iter / 2)
		{
			pos = (double)j / (fc->iter / 2);
			fc->palette[i + j] = interpolate(color1, color2, pos);
			j++;
		}
		color1 = color2;
		i += j;
	}
	fc->palette[fc->iter -1] = 0;
}

/* RAINBOW pastel */
void	set_color_rainbow(t_fractol *fc, int *color)
{
	int	i;

	i = 0;
	color[0] = 0xfbf8cc;
	color[1] = 0xfde4cf;
	color[2] = 0xffcfd2;
	color[3] = 0xf1c0e8;
	color[4] = 0xcfbaf0;
	color[5] = 0xa3c4f3;
	color[6] = 0x90dbf4;
	color[7] = 0x8eecf5;
	color[8] = 0x98f5e1;
	color[9] = 0xb9fbc0;
	while (i < fc->iter)
	{
		fc->palette[i] = color[i % 10];
		i++;
	}
	fc->palette[fc->iter - 1] = 0;
}
