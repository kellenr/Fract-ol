/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:52:15 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/19 22:40:55 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// fractal_options:
// Prints an explanation of the fractal options that can be specified
void	fractal_opt(void)
{
	ft_printf(P_B \
"\t+======================================================+\n" \
"\t|        "RT P_M"    🎨 Set of Fractals Availables  "RT P_B"           |\n" \
"\t|======================================================|\n" \
"\t|        Which fractal would you like to view?         |\n" \
"\t|                  M - Mandelbrot                      |\n" \
"\t|                  J - Julia                           |\n" \
"\t|                  T - Tricorn                         |\n" \
"\t|                  N - Nova                            |\n" \
"\t| "RT P_G" * Usage example:  ./fractol <set>   "RT P_B"                |\n" \
"\t|                "RT P_G"    ./fractol <set> <iter>   "RT P_B"         |\n" \
"\t+======================================================+\n" RT);
	ft_printf(P_B \
"\t|              "RT P_O"   🌟 Extra Note:    "RT P_B"                   |\n" \
"\t|         For Julia you can use the defaul mode        |\n" \
"\t| or you can provide the values for the initialization |\n" \
"\t|   of the fractal shape. Tha values must be between   |\n" \
"\t|     -2.0 and 2.0 and must contain a decimal point    |\n" \
"\t|       "RT P_G" * Example:  ./fractol j 0.285 0.01   "RT P_B"         |\n" \
"\t|                "RT P_G"    ./fractol j    "RT P_B"                   |\n" \
"\t+======================================================+\n" RT);
}

/* print_controls:
*	Prints a list of program controls to the standard output when the program
*	launches successfully.
*/
void	ft_control(void)
{
	ft_printf(P_P \
"\t+======================================================+\n" \
"\t|               "RT P_B"    🎮 controls 🎮 "RT P_P"                    |\n" \
"\t|======================================================|\n" \
"\t| WASD or arrow keys      : move view.                 |\n" \
"\t| +/- or scroll wheel     : zoom in and out.           |\n" \
"\t| Spacebar                : change color               |\n" \
"\t| 1, 2, 3, 4              : switch fractals.           |\n" \
"\t| H, J, K, L, P, O, I, M  : switch julia.              |\n" \
"\t| ESC or close window     : quit fract'ol.             |\n" \
"\t+======================================================+\n" RT);
}
