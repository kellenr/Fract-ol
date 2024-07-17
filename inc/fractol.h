/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:30:47 by keramos-          #+#    #+#             */
/*   Updated: 2024/07/01 16:31:10 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <X11/X.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>

/* COLOR intro */
# define RT			"\033[0m"
# define P_R		"\033[38;2;255;179;186m"
# define P_G		"\033[38;2;186;255;201m"
# define P_Y		"\033[38;2;255;255;186m"
# define P_B		"\033[38;2;186;225;255m"
# define P_L		"\033[38;2;255;186;255m"
# define P_M		"\033[38;2;200;162;200m"
# define P_P		"\033[1;38;2;255;209;220m"
# define P_O		"\033[38;2;255;223;186m"

/*  Dimensions	*/
# define WIDTH		900
# define HEIGHT		900
# define MAX_ITER	60

/* Events */
# define KEY_PLUS	61
# define MOUSE_UP	4
# define MOUSE_DOWN	5
# define MOUSE_BTN	1

/*  Fractal sets	*/
# define MANDELBROT	1
# define JULIA		2
# define TRICORN	3
# define NOVA		4

/* ************************************************************************** */
/*                                 STRUCT                                     */
/* ************************************************************************** */

//Complex values, reals and imaginaries
typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

/* Generic x and y position */
typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

/* Image Data Buffer Structure
	img:		Pointer to image struct
	pix:		Pointer to image pixel data
	bitp:		Bits per pixel
	ln_len:	Line length
	endian:		Endian*/
typedef struct s_imgs
{
	void	*img;
	char	*pix;
	int		bitp;
	int		ln_len;
	int		endian;
}				t_imgs;

//Struct for passing a range into scaling function
typedef struct s_range
{
	double		min;
	double		max;
}				t_range;

//This structure holds all necessary variables to draw and manage fractals.
//MLX = mlx_init and mlx_wind = new_window
typedef struct s_fractol
{
	void		*mlx;
	void		*mlx_window;
	t_imgs		img;
	double		esc;
	int			set;
	int			color;
	int			color_p;
	int			*palette;
	long		iter;
	t_range		r;
	t_range		i;
	t_complex	c;
	t_complex	z;
	t_complex	j;
}			t_fractol;

/* ************************************************************************** */
/*                                 UTILS                                      */
/* ************************************************************************** */

/* Mgs and argument */
int		arg_cmp(char *av, char *str, char c);
int		is_string_numeric(const char *str);
void	ft_empty(void);
int		opt_msg(void);
void	ft_intro_art(void);
void	fractal_opt(void);
void	ft_control(void);
void	julia_opt(void);
void	fail_float(void);

/* Handle float */
double	ft_atof(const char *str);
double	parse_decimal(const char *str, int *pos, double *val);
double	parse_integer(const char *str, int *pos);
double	parse_sign(const char *str, int *pos);

/* Check set */
void	get_set(t_fractol *fc, char **argv);
void	check_set(t_fractol *fc, int argc, char **argv);

/* Clean */
void	clean_free(t_fractol *fc);
int		close_handler(t_fractol *fc);
void	clean_init(t_fractol *f);
void	ft_error(void);

/* ************************************************************************** */
/*                                 SETUP                                      */
/* ************************************************************************** */

/* MLX */
void	window_init(t_fractol *fc);
void	init_color(t_fractol *fc);
void	ft_render(t_fractol *fc);
void	ft_events(t_fractol *fc);

/* Events */
int		key_handler(int keysym, t_fractol *fc);
void	handle_move(t_fractol *f, double move_x, double move_y);
void	handle_zoom(t_fractol *fc, double zoom);
void	ft_switch_set(t_fractol *fc, int keysym);
int		mouse_handler(int button, int x, int y, t_fractol *fc);
void	calculate_center(t_fractol *fc, int x, int y, t_complex *center);
void	zoom_in_center(t_fractol *fc, int x, int y, double zoom_factor);
void	zoom_out_center(t_fractol *fc, int x, int y, double zoom_factor);
int		key_julia_event(t_fractol *fc, int keysym);
void	handle_zoom_out(t_fractol *fc, double center_x, double center_y, \
			double zoom);

/* Initialization */
void	init_data(t_fractol *fc);
void	init(t_fractol *fc);
void	init_julia(t_fractol *fc, int argc, char **argv);
void	init_set(t_fractol *fc, int argc, char **argv);
int		handel_set(t_fractol *fc, double x, double y);
void	init_julia_params(t_fractol *fc, double j_r, double j_i);
void	init_set_params(t_fractol *fc, int i);
void	recoloring_img(t_fractol *f);

/* Color */
void	set_color(t_imgs *img, int x, int y, int nb);
void	ft_color(t_fractol *fc);
int		interpolate(int start, int end, double fraction);
void	set_color_one(t_fractol *fc, int color);
void	set_color_two(t_fractol *fc, int color1, int color2);
void	set_color_rainbow(t_fractol *fc, int *color);
void	reinit_img(t_fractol *f);

/* ************************************************************************** */
/*                                F SETS                                      */
/* ************************************************************************** */

/* Sets */
int		ft_tricorn(t_fractol *fc, double f_r, double f_i);
int		ft_mandelbrot(t_fractol *d, double f_r, double f_i);
int		ft_julia(t_fractol *fc, double zr, double zi);
int		ft_nova(t_fractol *fc, double f_r, double f_i);
int		ft_julia_shift(t_fractol *fc, int x, int y);

#endif
