/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:54:12 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/11 14:23:28 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

# define WIDTH	800
# define HEIGHT 800

/* Complex Number Structure
 *	r:	Real part
 *	i:	Imaginary part
 *	*/
typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

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

typedef struct s_range
{
	double		min;
	double		max;
}				t_range;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		input[256];
	int			input_len;
	void		(*func)(struct s_data *, int, int);
	t_position	pos;
	t_img		img;
	t_range		cc_range;
}	t_data;

void	draw_mandelbrot(t_data *data, int x, int y);
int		on_keypress(int keysym, t_data *data1);
int		close_on_escape(t_data *data);
void	iterate_screen(t_data *data, void (*f)(t_data *, int, int));
void	ft_put_pixel(t_img img, int x, int y, int color);
void	ft_render(t_data *d);

double	map(double ratio, double b1, double b2);
double	calculate_ratio(double y, double a1, double a2);

#endif