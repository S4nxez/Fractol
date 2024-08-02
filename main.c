/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:49:43 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/02 19:40:36 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	iterate_screen(void *ptr, void *wn, void (*f)(void *, void *, int, int))
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			f(ptr, wn, x, y);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	mlx_win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Fracto'l");
	if (mlx_win == NULL)
		return (1);
	iterate_screen(mlx_ptr, mlx_win, draw_mandelbrot);
	mlx_loop(mlx_ptr);
	return (0);
}
