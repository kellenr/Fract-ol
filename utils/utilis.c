/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:19:37 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/19 02:24:24 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* arg_cmp:
*	The given fractal argument and checks against
*	the name (i.e. "mandelbrot"), the associated letter (i.e. "M")
*	Returns true if the argument matches one of these requirements,
*	false if not.
*/
int	arg_cmp(char *argv, char *str, char c)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		argv[i] = ft_tolower(argv[i]);
		i++;
	}
	if (!ft_strncmp(argv, str, ft_strlen(str) + 1))
		return (1);
	else if (argv[1] == '\0' && (argv[0] == c))
	{
		return (1);
	}
	return (0);
}

/* ft_atof:
*	This funtion converts a string to a double-precision
*	floating-point number.
*	I just this function with julia parameters.
*/
double	ft_atof(const char *str)
{
	int		pos;
	double	val;
	int		i;
	int		sign;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.' \
			&& str[i] != '-' && str[i] != '+')
			fail_float();
	pos = 0;
	val = 0;
	sign = parse_sign(str, &pos);
	val = parse_integer(str, &pos);
	parse_decimal(str, &pos, &val);
	if (str[pos] != '\0')
		return (0.0);
	pos = 0;
	val *= sign;
	return (val);
}

/*Negative and positive sign */
double	parse_sign(const char *str, int *pos)
{
	if (str[*pos] == '-')
	{
		(*pos)++;
		return (-1.0);
	}
	else if (str[*pos] == '+')
		(*pos)++;
	return (1.0);
}

/* Numbers before the dot*/
double	parse_integer(const char *str, int *pos)
{
	double	val;

	val = 0.0;
	while (str[*pos] >= '0' && str[*pos] <= '9')
	{
		val = val * 10.0 + (str[*pos] - '0');
		(*pos)++;
	}
	return (val);
}

/* Number after the Dot*/
double	parse_decimal(const char *str, int *pos, double *val)
{
	double	decimal;

	if (str[*pos] == '.')
	{
		(*pos)++;
		decimal = 1.0;
		while (str[*pos] >= '0' && str[*pos] <= '9')
		{
			*val = *val * 10.0 + (str[*pos] - '0');
			decimal *= 10.0;
			(*pos)++;
		}
		*val /= decimal;
	}
	return (*val);
}
