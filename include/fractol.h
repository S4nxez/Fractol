/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:54:12 by dansanc3          #+#    #+#             */
/*   Updated: 2024/09/09 10:21:40 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h>
# include "ft_printf.h"
# include "libft.h"

# define WIDTH	800
# define HEIGHT	800

typedef struct pos
{
	double	x;
	double	y;
	double	zoom;
}	t_position;

typedef struct s_img
{
	void	*img;
	char	*pix;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			(*func)(struct s_data *, int, int);
	int				iter;
	int				color_i;
	unsigned int	color[4];
	t_position		pos;
	t_img			img;
}	t_data;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

void	draw_mandelbrot(t_data *data, int x, int y);
void	draw_julia(t_data *data, int x, int y);
int		on_keypress(int keysym, t_data *data1);
int		close_on_escape(t_data *data);
void	iterate_screen(t_data *data);
void	ft_put_pixel(t_img img, int x, int y, int color);
double	map(double ratio, double b1, double b2);
double	calculate_ratio(double y, double a1, double a2);
int		calc_bright(t_complex *z, t_complex *c, t_data *d);
int		mouse_hook(int mouse_code, int x, int y, t_data *data);
void	draw_newton(t_data *data, int x, int y);
#endif