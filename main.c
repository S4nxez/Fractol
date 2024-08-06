/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:49:43 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/06 11:22:30 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	iterate_screen(t_data *data, void (*f)(t_data *data, int, int))
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			f(data, x, y);
			y++;
		}
		x++;
	}
}

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
	iterate_screen(dat, draw_mandelbrot);
	mlx_hook(dat->win_ptr, KeyRelease, KeyReleaseMask, on_keypress, dat);
	mlx_hook(dat->win_ptr, DestroyNotify, NoEventMask, close_on_escape, dat);
	mlx_loop(dat->mlx_ptr);
	return (0);
}
