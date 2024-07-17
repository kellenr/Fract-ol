/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:18:20 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/20 15:58:41 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keysym, t_fractol *fc)
{
	if (keysym == XK_Escape)
		close_handler(fc);
	else if (keysym == XK_Up || keysym == XK_w)
		handle_move(fc, 0.0, 0.1);
	else if ((keysym == XK_Down) || (keysym == XK_s))
		handle_move(fc, 0.0, -0.1);
	else if (keysym == XK_Left || keysym == XK_a)
		handle_move(fc, -0.1, 0.0);
	else if (keysym == XK_Right || keysym == XK_d)
		handle_move(fc, 0.1, 0.0);
	else if (keysym == KEY_PLUS)
		handle_zoom(fc, 0.5);
	else if (keysym == XK_minus)
		handle_zoom(fc, 2);
	else if (keysym == XK_space)
		ft_color(fc);
	else if ((keysym == XK_1) || (keysym == XK_2) || (keysym == XK_3) \
			|| (keysym == XK_4))
		ft_switch_set(fc, keysym);
	else if (!key_julia_event(fc, keysym))
		return (1);
	ft_render(fc);
	return (0);
}

void	handle_move(t_fractol *fc, double move_x, double move_y)
{
	double	w;
	double	h;

	w = (fc->r.max - fc->r.min);
	h = (fc->i.max - fc->i.min);
	fc->r.max += w * move_x;
	fc->r.min += w * move_x;
	fc->i.min += h * move_y;
	fc->i.max += h * move_y;
}

void	handle_zoom(t_fractol *fc, double zoom)
{
	double	center_x;
	double	center_y;

	center_x = (fc->r.min - fc->r.max);
	center_y = (fc->i.max - fc->i.min);
	fc->r.max += (center_x - zoom * center_x) / 2;
	fc->r.min = fc->r.max + zoom * center_x;
	fc->i.min += (center_y - zoom * center_y) / 2;
	fc->i.max = fc->i.min + zoom * center_y;
}

void	ft_switch_set(t_fractol *fc, int keysym)
{
	if (keysym == XK_1)
		fc->set = MANDELBROT;
	else if (keysym == XK_2)
		fc->set = JULIA;
	else if (keysym == XK_3)
		fc->set = TRICORN;
	else if (keysym == XK_4)
		fc->set = NOVA;
	init(fc);
	ft_render(fc);
}

void	init(t_fractol *fc)
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
	}
	else
	{
		fc->esc = 4.0;
		fc->r.min = -2.0;
		fc->i.min = -1.5;
		fc->r.max = 1.0;
		fc->i.max = 1.5;
	}
}
