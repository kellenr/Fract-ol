/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:10:47 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/20 14:09:59 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* if is just one argument print a message and give some options of
how the project works */
void	ft_empty(void)
{
	ft_printf("\033[1;31m\n\t\tNo arguments provided.\n\033[0m");
	opt_msg();
}

// opt_msg:
// Prints a help message to the standard output to explain the program options.
int	opt_msg(void)
{
	ft_intro_art();
	fractal_opt();
	return (0);
}

/* get_set:
*	Retrieves the set specified in program arguments.
*	If no valid set was provided, it displays a help
*	message and quits the program.
*/
void	get_set(t_fractol *fc, char **argv)
{
	if (arg_cmp(argv[1], "mandelbrot", 'm'))
		fc->set = MANDELBROT;
	else if (arg_cmp(argv[1], "julia", 'j'))
		fc->set = JULIA;
	else if (arg_cmp(argv[1], "tricorn", 't'))
		fc->set = TRICORN;
	else if (arg_cmp(argv[1], "nova", 'n'))
		fc->set = NOVA;
	else
	{
		ft_printf("\033[1;31m\n\t\tInvalid fractal type: %s\n\033[0m", argv[1]);
		opt_msg();
		exit(EXIT_FAILURE);
	}
}

/* check if the argument are correct and select the correct set */
void	check_set(t_fractol *fc, int argc, char **argv)
{
	get_set(fc, argv);
	if (fc->set == JULIA)
		init_julia(fc, argc, argv);
	else if (fc->set == MANDELBROT)
		init_set(fc, argc, argv);
	else if (fc->set == TRICORN)
		init_set(fc, argc, argv);
	else if (fc->set == NOVA)
		init_set(fc, argc, argv);
}

/* check is the value for mandelbrot is an interger */
int	is_string_numeric(const char *str)
{
	if (!str || *str == '\0')
		return ((0));
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_printf(P_R"Error: Invalid float\n"RT);
			exit(EXIT_FAILURE);
		}
		str++;
	}
	return (1);
}
