/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:54:30 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/11 16:00:24 by dansanc3         ###   ########.fr       */
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
			draw_mandelbrot(d, x, y);
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img, 0, 0);
	return ;
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