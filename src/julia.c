/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:23:53 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/23 17:08:10 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_data *data, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		bright;

	c.r = -0.7;
	c.i = 0.27015;
	z.r = map(calculate_ratio(x, 0, WIDTH), data->pos.x - data->pos.zoom,
			data->pos.x + data->pos.zoom);
	z.i = map(calculate_ratio(y, 0, HEIGHT), data->pos.y - data->pos.zoom,
			data->pos.y + data->pos.zoom);
	bright = map(calculate_ratio(calc_iterations(&z, &c, data),
				0, data->iter), 0, 0x00FF00);
	ft_put_pixel(data->img, x, y, bright);
}
