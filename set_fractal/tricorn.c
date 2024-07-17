/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 00:27:49 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/19 15:30:35 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_tricorn(t_fractol *fc, double f_r, double f_i)
{
	double	tmp;
	int		i;

	fc->z.r = f_r;
	fc->z.i = f_i;
	i = 0;
	while (i <= fc->iter)
	{
		if ((fc->z.r * fc->z.r) + (fc->z.i * fc->z.i) > fc->esc)
			break ;
		tmp = (fc->z.r * fc->z.r) - (fc->z.i * fc-> z.i) + f_r;
		fc->z.i = (-2 * fc->z.r * fc->z.i) + f_i;
		fc->z.r = tmp;
		i++;
	}
	return (i);
}
