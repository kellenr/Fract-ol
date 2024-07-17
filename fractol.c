/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:29:50 by kellenr           #+#    #+#             */
/*   Updated: 2024/05/15 13:50:44 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fc;

	if (argc < 2)
	{
		ft_empty();
		exit(EXIT_FAILURE);
	}
	clean_init(&fc);
	check_set(&fc, argc, argv);
	window_init(&fc);
	ft_control();
	ft_render(&fc);
	mlx_loop(fc.mlx);
	exit(EXIT_SUCCESS);
}
