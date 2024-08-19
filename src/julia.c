/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:23:53 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/14 14:36:24 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_data *data, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		bright;

	c.r = map(calculate_ratio(x, 0, WIDTH), data->pos.x - data->pos.zoom,
			data->pos.x + data->pos.zoom);
	c.i = map(calculate_ratio(y, 0, HEIGHT), data->pos.y - data->pos.zoom,
			data->pos.y + data->pos.zoom);
	z.r = map(calculate_ratio(x, 0, WIDTH), -2, 2);
	z.i = map(calculate_ratio(y, 0, HEIGHT), -2, 2);
	bright = calc_mandelbrot_iterations(&z, &c, data);
	ft_put_pixel(data->img, x, y, bright * 0x010101);
}
