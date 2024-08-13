/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:54:30 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/12 18:26:59 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterate_screen(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			d->func(d, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img, 0, 0);
}

void	ft_put_pixel(t_img img, int x, int y, int color)
{
	int	offset;

	offset = (y * img.line_len) + (x * (img.bpp / 8));
	*(unsigned *)(img.pix + offset) = color;
}
