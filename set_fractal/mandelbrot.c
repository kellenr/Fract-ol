/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:13:51 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/16 12:48:19 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//The function that has to be satisfied is f(z) = z^2 + c
// Z is for complex math
// z start (0,0) and our point c (x, yi)
// i^2 = -1

int	ft_mandelbrot(t_fractol *fc, double f_r, double f_i)
{
	double	tmp;
	int		i;

	fc->z.r = 0.0;
	fc->z.i = 0.0;
	i = 0;
	while (i <= fc->iter)
	{
		if ((fc->z.r * fc->z.r) + (fc->z.i * fc->z.i) > fc->esc)
			break ;
		tmp = (fc->z.r * fc->z.r) - (fc->z.i * fc-> z.i) + f_r;
		fc->z.i = (2 * fc->z.r * fc->z.i) + f_i;
		fc->z.r = tmp;
		i++;
	}
	return (i);
}
