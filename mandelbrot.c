/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:31:55 by dansanc3          #+#    #+#             */
/*   Updated: 2024/07/31 20:13:34 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include <math.h>

#define WIDTH	600
#define HEIGHT	600

double map(double y, double a1, double a2, double b1, double b2) {
    return b1 + ((y - a1) * (b2 - b1)) / (a2 - a1);
}

int main()
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;
	double	a;
	double	b;
	double	bright;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return 1;

	mlx_win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Fracto'l");
	if (mlx_win == NULL)
		return 1;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			a = map(x, 0, WIDTH, -2, 2);
			b = map(y, 0, HEIGHT, -2, 2);

			double ca = a;
			double cb = b;

			int n = 0;
			while (n < 100)
			{
				double aa = a * a - b * b;
				double bb = 2 * a * b;
				a = aa + ca;
				b = bb + cb;
				if (fabs(a + b) > 16)
					break;
				n++;
			}

			bright = map(n,0, 100, 0, 0x00FF00);
			mlx_pixel_put(mlx_ptr, mlx_win, x, y, bright);
			x++;
		}
		y++;
	}
	mlx_loop(mlx_ptr);

	return 0;
}
