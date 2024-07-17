/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:30:05 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/20 04:07:47 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

	// Constants for the fractal: z^3 - 1 = 0, thus f'(z) = 3z^2
	// Relaxation factor, can be adjusted for different visuals
	// Temporaries for real and imaginary parts of new z
	// Initial z, typically starts from the constant part (c_r, c_i)
int	ft_nova(t_fractol *fc, double f_r, double f_i)
{
	t_complex	fz;
	t_complex	dfz;
	t_complex	upt;
	double		dv;
	int			i;

	i = 0;
	fc->z.r = f_r;
	fc->z.i = f_i;
	while (i <= fc->iter)
	{
		fz.r = fc->z.r * ((fc->z.r * fc->z.r) - 3 * (fc->z.i * fc->z.i)) - 1;
		fz.i = fc->z.i * (3 * (fc->z.r * fc->z.r) - (fc->z.i * fc->z.i));
		dfz.r = 3 * ((fc->z.r * fc->z.r) - (fc->z.i * fc->z.i));
		dfz.i = 6 * fc->z.r * fc->z.i;
		dv = dfz.r * dfz.r + dfz.i * dfz.i;
		upt.r = (fz.r * dfz.r + fz.i * dfz.i) / dv;
		upt.i = (fz.i * dfz.r - fz.r * dfz.i) / dv;
		fc->z.r -= 1.0 * upt.r;
		fc->z.i -= 1.0 * upt.i;
		if ((upt.r * upt.r + upt.i * upt.i) < 0.000001)
			break ;
		i++;
	}
	return (i);
}
