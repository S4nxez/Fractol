/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:04:00 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/28 21:09:08 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_on_escape(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
	return (0);
}

void	input_translation(int keysym, t_data *data)
{
	if (keysym == 'w')
		data->pos.y -= data->pos.zoom * 0.2;
	else if (keysym == 's')
		data->pos.y += data->pos.zoom * 0.2;
	else if (keysym == 'a')
		data->pos.x -= data->pos.zoom * 0.2;
	else if (keysym == 'd')
		data->pos.x += data->pos.zoom * 0.2;
	else if (keysym == '+')
		data->pos.zoom *= 0.7;
	else if (keysym == '-')
		data->pos.zoom /= 0.7;
	else if (keysym == 'n')
		data->iter += 10;
	else if (keysym == 'm' && data->iter > 10)
		data->iter -= 10;
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		close_on_escape(data);
	}
	else
	{
		ft_printf("Pressed key: %d\n", keysym);
		input_translation(keysym, data);
		iterate_screen(data);
	}
	return (keysym);
}

/*int	mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	if (mouse_code == 4)
	{
		data->pos.zoom *= 0.7;
	}
	else if (mouse_code == 5)
	{
		data->pos.zoom /= 0.7;
	}
	data->pos.x += (data->pos.zoom * 0.5) * x;
	data->pos.y += (data->pos.zoom * 0.5) * y;
	iterate_screen(data);
	return (mouse_code);
}*/

int	mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	double	fractal_x = (x - WIDTH / 2) * data->pos.zoom / WIDTH + data->pos.x;
	double	fractal_y = (y - HEIGHT / 2) * data->pos.zoom / HEIGHT + data->pos.y;

	if (mouse_code == 4)
	{
		data->pos.zoom *= 0.7;
	}
	else if (mouse_code == 5)
	{
		data->pos.zoom /= 0.7;
	}
	data->pos.x = fractal_x - (x - WIDTH / 2) * data->pos.zoom / WIDTH;
	data->pos.y = fractal_y - (y - HEIGHT / 2) * data->pos.zoom / HEIGHT;
	iterate_screen(data);
	return (0);
}
