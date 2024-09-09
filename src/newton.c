/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:27:02 by dansanc3          #+#    #+#             */
/*   Updated: 2024/09/09 12:52:03 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_abs(t_complex z)
{
	return (sqrt(z.r * z.r + z.i * z.i));
}

void	draw_newton(t_data *data, int x, int y)
{
	t_complex	roots[3] = {
		{1, 0},
		{-0.5, sqrt(3) / 2},
		{-0.5, -sqrt(3) / 2}
	};
	double	zx = (x - WIDTH / 2.0) * 4.0 / WIDTH / data->pos.zoom + data->pos.x;
	double	zy = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / data->pos.zoom + data->pos.y;
	t_complex z = {zx, zy};
	for (int iteration = 0; iteration < data->iter; iteration++)
	{
		// z = z - Function(z) / Derivative(z)
		double		z_r2 = z.r * z.r;
		double		z_i2 = z.i * z.i;
		t_complex	f_z = {z_r2 * z.r - 3 * z.r * z_i2 - 1, 3 * z_r2 * z.i - z_i2 * z.i};
		t_complex	df_z = {3 * z_r2 - 3 * z_i2, 6 * z.r * z.i};
		double		denom = df_z.r * df_z.r + df_z.i * df_z.i;
		t_complex	div = {(f_z.r * df_z.r + f_z.i * df_z.i) / denom, (f_z.i * df_z.r - f_z.r * df_z.i) / denom};
		z.r -= div.r;
		z.i -= div.i;
		for (int i = 0; i < 3; i++)
		{
			t_complex difference = {z.r - roots[i].r, z.i - roots[i].i};
			if (complex_abs(difference) < 0.000001) //0.000001 es la tolerancia
			{
				ft_put_pixel(data->img, x, y, map(calculate_ratio(i, 0, 3), 0,
							data->color[data->color_i]));
				return ;
			}
		}
	}
	// Si no se encuentra una raíz, se puede asignar un color por defecto (negro)
	ft_put_pixel(data->img, x, y, 0x000000);
}
