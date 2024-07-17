/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:20:55 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/20 14:06:51 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* print error and exit */
void	ft_error(void)
{
	perror("Error working with the window");
	exit(EXIT_FAILURE);
}

/* clean_exit:
*	Destroys the window, the MLX image and the MLX instance,
*	and frees the color palette, before ending the MLX loop
*	and destroying the display. Exits the process with the provided
*	exit code.
*/
void	clean_free(t_fractol *fc)
{
	if (fc->mlx_window)
	{
		mlx_destroy_window(fc->mlx, fc->mlx_window);
		mlx_destroy_display(fc->mlx);
		free(fc->mlx);
	}
	if (fc->img.img)
	{
		mlx_destroy_image(fc->mlx, fc->img.img);
		mlx_destroy_window(fc->mlx, fc->mlx_window);
		mlx_destroy_display(fc->mlx);
		free(fc->mlx);
	}
	if (fc->mlx)
	{
		mlx_destroy_display(fc->mlx);
		free(fc->mlx);
	}
	if (fc->palette)
		free(fc->palette);
	ft_error();
}

/* destry the imag and the window, and free everytnig after colse the window */
int	close_handler(t_fractol *fc)
{
	mlx_destroy_image(fc->mlx, fc->img.img);
	mlx_destroy_window(fc->mlx, fc->mlx_window);
	mlx_destroy_display(fc->mlx);
	free(fc->mlx);
	free(fc->palette);
	exit(EXIT_SUCCESS);
}

/* initialize everything to zero or NULL before start it */
void	clean_init(t_fractol *fc)
{
	fc->mlx = NULL;
	fc->mlx_window = NULL;
	fc->img.img = NULL;
	fc->img.pix = NULL;
	fc->palette = NULL;
	fc->color_p = -1;
	fc->set = -1;
	fc->r.min = 0;
	fc->r.max = 0;
	fc->i.min = 0;
	fc->i.max = 0;
	fc->j.r = 0;
	fc->j.i = 0;
	fc->color = 0;
}

/* Check is julia Values are floats  */
void	fail_float(void)
{
	ft_printf(P_R"Error: Invalid float\n"RT);
	ft_printf("\t*Julia works with 2 parameter between -2.0 and 2.0\n" \
			"\t*The Julia Fractol only recive float numbers\n");
	exit(EXIT_FAILURE);
}
