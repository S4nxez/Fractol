/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:49:43 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/29 11:01:31 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <X11/keysym.h>

int	input_validator(void)
{
	char	*entrada;
	int		ret;

	ret = 0;
	while (ret == 0)
	{
		entrada = get_next_line(1);
		if (!entrada)
			return (1);
		if ((*entrada != '1' && *entrada != '2') || entrada[1] != '\n')
		{
			ft_printf("Entrada no válida, por favor, introduce 1 o 2\n");
		}
		else
			ret = *entrada - '0';
		free(entrada);
	}
	return (ret);
}

void	main_menu(t_data *data)
{
	int	input;

	ft_printf("Selecciona el fractal: \n1.Mandelbrot\n2.Julia\n");
	input = input_validator();
	if (input == 1)
	{
		data->pos.x = -0.735;
		data->pos.y = 0;
		data->pos.zoom = 1.35;
		data->iter = 50;
		data->func = draw_mandelbrot;
	}
	else if (input == 2)
	{
		data->pos.x = 0;
		data->pos.y = 0;
		data->pos.zoom = 1.5;
		data->iter = 50;
		data->func = draw_julia;
	}
}

int	main(void)
{
	t_data	*dat;

	dat = (t_data *)malloc(sizeof(t_data));
	if (dat == NULL)
		return (1);
	main_menu(dat);
	dat->mlx_ptr = mlx_init();
	if (dat->mlx_ptr == NULL)
		return (1);
	dat->win_ptr = mlx_new_window(dat->mlx_ptr, WIDTH, HEIGHT, "Fracto'l");
	if (dat->win_ptr == NULL)
		return (1);
	dat->img.img = mlx_new_image(dat->mlx_ptr, WIDTH, HEIGHT);
	dat->img.pix = mlx_get_data_addr(dat->img.img, &dat->img.bpp,
			&dat->img.line_len, &dat->img.endian);
	iterate_screen(dat);
	mlx_hook(dat->win_ptr, KeyRelease, KeyReleaseMask, on_keypress, dat);
	mlx_mouse_hook(dat->win_ptr, mouse_hook, dat);
	mlx_hook(dat->win_ptr, DestroyNotify, NoEventMask, close_on_escape, dat);
	mlx_loop(dat->mlx_ptr);
	mlx_destroy_image(dat->mlx_ptr, dat->img.img);
	mlx_destroy_window(dat->mlx_ptr, dat->win_ptr);
	mlx_destroy_display(dat->mlx_ptr);
	free(dat);
	return (0);
}
