/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:27:02 by dansanc3          #+#    #+#             */
/*   Updated: 2024/09/15 12:18:29 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	iterate_z(t_complex z)
{
	double		z_r2;
	double		z_i2;
	t_complex	f_z;
	t_complex	df_z;
	double		denom;

	z_r2 = z.r * z.r;
	z_i2 = z.i * z.i;
	f_z.r = z_r2 * z.r - 3 * z.r * z_i2 - 1;
	f_z.i = 3 * z_r2 * z.i - z_i2 * z.i;
	df_z.r = 3 * z_r2 - 3 * z_i2;
	df_z.i = 6 * z.r * z.i;
	denom = df_z.r * df_z.r + df_z.i * df_z.i;
	z.r -= (f_z.r * df_z.r + f_z.i * df_z.i) / denom;
	z.i -= (f_z.i * df_z.r - f_z.r * df_z.i) / denom;
	return (z);
}

int	check_roots(t_complex z, t_complex roots[3], double tolerance)
{
	t_complex	diff;
	int			o;

	o = 0;
	while (o < 3)
	{
		diff.r = z.r - roots[o].r;
		diff.i = z.i - roots[o].i;
		if (sqrt(diff.r * diff.r + diff.i * diff.i) < tolerance)
			return (o);
		o++;
	}
	return (-1);
}

t_complex	*initialize_roots(void)
{
	t_complex	*roots;

	roots = (t_complex *)malloc(3 * sizeof(t_complex));
	if (roots == NULL)
		return (NULL);
	roots[0].r = 1;
	roots[0].i = 0;
	roots[1].r = -0.5;
	roots[1].i = sqrt(3) / 2;
	roots[2].r = -0.5;
	roots[2].i = -sqrt(3) / 2;
	return (roots);
}

void	main_loop(t_data *data, int x, int y, t_complex z)
{
	t_complex	*roots;
	int			root_index;
	int			i;

	roots = initialize_roots();
	if (roots == NULL)
		return ;
	i = 0;
	while (i < data->iter)
	{// z = z - Function(z) / Derivative(z)
		z = iterate_z(z);
		root_index = check_roots(z, roots, 0.000001);
		if (root_index != -1)
		{
			ft_put_pixel(data->img, x, y, map(calculate_ratio(root_index, 0, 3),
					0, data->color[data->color_i]));
			free(roots);
			return ;
		}
		i++;
	}
	free(roots);
	ft_put_pixel(data->img, x, y, 0x000000); // Si no se encuentra una raíz, se asigna un color por defecto (negro)
}

void	draw_newton(t_data *data, int x, int y)
{
	t_complex	z;
	double		zx;
	double		zy;

	zx = (x - WIDTH / 2.0) * 4.0 / WIDTH / data->pos.zoom + data->pos.x;
	zy = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / data->pos.zoom + data->pos.y;
	z.i = zx;
	z.r = zy;
	main_loop(data, x, y, z);
}
