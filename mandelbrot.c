/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:31:55 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/06 11:45:37 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include <math.h>
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

int	calc_mandelbrot_iterations(double *a, double *b, double ca, double cb)
{
	double	aa;
	double	bb;
	int		n;

	n = 0;
	while (n < 100)
	{
		aa = (*a) * (*a) - (*b) * (*b);
		bb = 2 * (*a) * (*b);
		*a = aa + ca;
		*b = bb + cb;
		if (fabs(*a + *b) > 16)
			break ;
		n++;
	}
	return (n);
}

int	translate(t_data *data)
{
	int	i;
	int	aumento;

	aumento = 2;
	i = 0;
	while (data->input[i] != '\0')
	{
		if (data->input[i] == '-')
			aumento--;
		if (data->input[i] == '+')
			aumento++;
		i++;
	}
	return (aumento);
}

void	draw_mandelbrot(t_data *data, int x, int y)
{
	double	a;
	double	b;
	double	ca;
	double	cb;
	double	bright;

	a = map(calculate_ratio(x, 0, WIDTH), -translate(data), translate(data));
	b = map(calculate_ratio(y, 0, HEIGHT), -translate(data), translate(data));
	ca = a;
	cb = b;
	bright = map(calculate_ratio(calc_mandelbrot_iterations(&a, &b, ca, cb),
				0, 100), 0, 0x00FF00);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, bright);
}
