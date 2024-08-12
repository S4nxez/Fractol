/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:49:43 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/12 17:16:46 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <X11/keysym.h>

int	main(void)
{
	t_data	*dat;

	dat = (t_data *)malloc(sizeof(t_data));
	if (dat == NULL)
		return (1);
	dat->mlx_ptr = mlx_init();
	if (dat->mlx_ptr == NULL)
		return (1);
	dat->win_ptr = mlx_new_window(dat->mlx_ptr, WIDTH, HEIGHT, "Fracto'l");
	if (dat->win_ptr == NULL)
		return (1);
	dat->func = draw_mandelbrot;
	dat->pos.x = -0.735;
	dat->pos.y = 0;
	dat->pos.zoom = 1.35;
	dat->img.img = mlx_new_image(dat->mlx_ptr, WIDTH, HEIGHT);
	dat->img.pix = mlx_get_data_addr(dat->img.img, &dat->img.bpp,
			&dat->img.line_len, &dat->img.endian);
	iterate_screen(dat);
	mlx_hook(dat->win_ptr, KeyRelease, KeyReleaseMask, on_keypress, dat);
	mlx_hook(dat->win_ptr, DestroyNotify, NoEventMask, close_on_escape, dat);
	mlx_loop(dat->mlx_ptr);
	return (0);
}
