/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:31:55 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/11 16:05:10 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

// función que usaría si norminette no existiese
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

int	calc_mandelbrot_iterations(double *zr, double *zi, double cr, double ci)
{
	double	tmp;
	int		i;

	i = 0;
	*zr = 0;
	*zi = 0;
	while (i < 100)
	{
		if ((*zr * *zr + *zi * *zi) > 16.0)
			break ;
		tmp = 2 * (*zr) * (*zi) + ci;
		*zr = (*zr * *zr - *zi * *zi) + cr;
		*zi = tmp;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_data *data, int x, int y)
{
	double	a;
	double	b;
	double	ca;
	double	cb;
	double	bright;

	a = map(calculate_ratio(x, 0, WIDTH), data->pos.x - data->pos.zoom,
			data->pos.x + data->pos.zoom);
	b = map(calculate_ratio(y, 0, HEIGHT), data->pos.y - data->pos.zoom,
			data->pos.y + data->pos.zoom);
	ca = a;
	cb = b;
	bright = map(calculate_ratio(calc_mandelbrot_iterations(&a, &b, ca, cb),
				0, 100), 0, 0x00FF00);
	ft_put_pixel(data->img, x, y, bright);
}
