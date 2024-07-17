/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:19:06 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/19 17:49:49 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Helper function to calculate center coordinates
void	calculate_center(t_fractol *fc, int x, int y, t_complex *center)
{
	double	width;
	double	height;

	width = fc->r.max - fc->r.min;
	height = fc->i.max - fc->i.min;
	center->r = fc->r.min + (double)x * width / WIDTH;
	center->i = fc->i.max - (double)y * height / HEIGHT;
}

// Helper function to handle zoom and re-center
void	zoom_in_center(t_fractol *fc, int x, int y, double zoom_factor)
{
	double		width;
	double		height;
	t_complex	old_center;
	t_complex	new_center;
	t_pos		move;

	calculate_center(fc, x, y, &old_center);
	handle_zoom(fc, zoom_factor);
	calculate_center(fc, x, y, &new_center);
	width = fc->r.max - fc->r.min;
	height = fc->i.max - fc->i.min;
	move.x = (old_center.r - new_center.r) / width;
	move.y = (old_center.i - new_center.i) / height;
	handle_move(fc, move.x, move.y);
}

int	mouse_handler(int button, int x, int y, t_fractol *fc)
{
	if (button == MOUSE_UP)
		zoom_in_center(fc, x, y, 0.5);
	else if (button == MOUSE_DOWN)
		zoom_out_center(fc, x, y, 2.0);
	else if (button == MOUSE_BTN)
	{
		if (fc->set == JULIA)
			ft_julia_shift(fc, x, y);
	}
	ft_render(fc);
	return (0);
}

void	zoom_out_center(t_fractol *fc, int x, int y, double zoom_factor)
{
	t_complex	center;

	calculate_center(fc, x, y, &center);
	handle_zoom_out(fc, center.r, center.i, zoom_factor);
}

void	handle_zoom_out(t_fractol *fc, double center_x, double center_y, \
			double zoom)
{
	double	new_width;
	double	new_height;

	new_width = (fc->r.max - fc->r.min) * zoom;
	new_height = (fc->i.max - fc->i.min) * zoom;
	center_x = (fc->r.max + fc->r.min) / 2;
	center_y = (fc->i.max + fc->i.min) / 2;
	fc->r.min = center_x - new_width / 2;
	fc->r.max = center_x + new_width / 2;
	fc->i.min = center_y - new_height / 2;
	fc->i.max = center_y + new_height / 2;
}
