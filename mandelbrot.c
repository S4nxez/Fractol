/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:31:55 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/07 19:52:39 by dansanc3         ###   ########.fr       */
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

float	trslt(t_data *data, char coord)
{
	int		i;
	float	increase;

	increase = 2.5;
	i = 0;
	while (data->input[i] != '\0')
	{
		if (data->input[i] == '+')
			increase /= 1.2;
		if (data->input[i] == '-')
			increase *= 1.2;
		if (coord == 'x')
		{
			if (data->input[i] == 'a')
				increase *= 2;
			if (data->input[i] == 'd')
				increase /= 2;
		}
		if (coord == 'y')
		{
			if (data->input[i] == 's')
				increase *= 1.2;
			if (data->input[i] == 'w')
				increase /=1.2;
		}
		i++;
	}
	return (increase);
}

void	draw_mandelbrot(t_data *data, int x, int y)
{
	double	a;
	double	b;
	double	ca;
	double	cb;
	double	bright;

	a = map(calculate_ratio(x, 0, WIDTH), -trslt(data, 'x'), trslt(data, 'y'));
	b = map(calculate_ratio(y, 0, HEIGHT), -trslt(data, 'x'), trslt(data, 'y'));
	ca = a;
	cb = b;
	bright = map(calculate_ratio(calc_mandelbrot_iterations(&a, &b, ca, cb),
				0, 100), 0, 0x00FF00);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, bright);
}
