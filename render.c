/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:54:30 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/10 22:03:44 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render(t_data *d)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_select_set(d, x, y);
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img, 0, 0);
	ft_render_ui(d);
	return ;
}
static void	ft_set_range(t_data *d, t_complex *c, int x, int y)
{
	c->r = (ft_map(x, d->win_size, d->cc_range) * d->zoom) + d->x_offset;
	d->cc_range.min = -2.0;
	d->cc_range.max = 2.0;
	c->i = (ft_map(y, d->win_size, d->cc_range) * d->zoom) + d->y_offset;
}

/*	ft_put_pixel : Puts a pixel to the data array of an image.
 *										 img->bpp
 *	offset = (y * img->line_len) + ( x * -------- )
 *										    8
 *		offset : stores the byte offset within the image data array where the
 *		information should be placed;, accounting for the possibility of
 *		padding bytes at the end of each row;
 *		1. Multiply the y-coordinate by the line length to find the starting
 *		position of the row in the buffer. This accounts for the width of the
 *		image and any padding.
 *		2. Multiply the x-coordinate by the size of each pixel in bytes (bits
 *		per_pixel / 8) to find the position of the pixel within the row.
 *		3. Add these two values together to get the overall byte offset within
 *		the buffer.
 *
 *		Note: This formula assumes that the image data is stored in a linear
 *		block of memory, row by row, without any compression or interlacing.
 *	*/

void	ft_put_pixel(t_img img, int x, int y, int color)
{
	int		offset;

	offset = (y * img.line_len) + (x * (img.bpp / 8));
	*(unsigned *)(img.pix + offset) = color;
}