/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:31:55 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/12 18:49:43 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

// función que usaría pero norminette no lo permite
/*
double map(double y, double a1, double a2, double b1, double b2) {
	return b1 + ((y - a1) * (b2 - b1)) / (a2 - a1);
}
*/

double	calculate_ratio(double y, double a1, double a2)
{
	return ((y - a1) / (a2 - a1));
}

double	map(double ratio, double b1, double b2)
{
	return (b1 + ratio * (b2 - b1));
}

int	calc_mandelbrot_iterations(t_complex *z, t_complex *c, t_data *d)
{
	double	tmp;
	int		i;

	i = 0;
	z->r = 0;
	z->i = 0;
	while (i < d->iter)
	{
		if ((z->r * z->r + z->i * z->i) > 16.0)
			break ;
		tmp = 2 * (z->r) * (z->i) + c->i;
		z->r = (z->r * z->r - z->i * z->i) + c->r;
		z->i = tmp;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_data *data, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		bright;

	c.r = map(calculate_ratio(x, 0, WIDTH), data->pos.x - data->pos.zoom,
			data->pos.x + data->pos.zoom);
	c.i = map(calculate_ratio(y, 0, HEIGHT), data->pos.y - data->pos.zoom,
			data->pos.y + data->pos.zoom);
	bright = map(calculate_ratio(calc_mandelbrot_iterations(&z, &c, data),
				0, data->iter), 0, 0x00FF00);
	ft_put_pixel(data->img, x, y, bright);
}
