/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:04:00 by dansanc3          #+#    #+#             */
/*   Updated: 2024/09/07 19:16:33 by dansanc3         ###   ########.fr       */
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

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		close_on_escape(data);
	else if (keysym == 'w' || keysym == 65362)
		data->pos.y -= data->pos.zoom * 0.2;
	else if (keysym == 's' || keysym == 65364)
		data->pos.y += data->pos.zoom * 0.2;
	else if (keysym == 'a' || keysym == 65361)
		data->pos.x -= data->pos.zoom * 0.2;
	else if (keysym == 'd' || keysym == 65363)
		data->pos.x += data->pos.zoom * 0.2;
	else if (keysym == '+')
		data->pos.zoom *= 0.7;
	else if (keysym == '-')
		data->pos.zoom /= 0.7;
	else if (keysym == 'n')
		data->iter += 10;
	else if (keysym == 'm' && data->iter > 10)
		data->iter -= 10;
	else if (keysym == 'c' && data->color_i == 3)
		data->color_i = -1;
	if (keysym == 'c')
		data->color_i++;
	iterate_screen(data);
	return (keysym);
}

int	mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	if (mouse_code == 4)
		data->pos.zoom *= 0.7;
	if (mouse_code == 5)
		data->pos.zoom /= 0.7;
	if (((mouse_code == 4 || mouse_code == 1) && x > WIDTH / 2)
		|| (mouse_code == 5 && x < WIDTH / 2))
		data->pos.x += data->pos.zoom * 0.2;
	if (((mouse_code == 4 || mouse_code == 1) && x < WIDTH / 2)
		|| (mouse_code == 5 && x > WIDTH / 2))
		data->pos.x -= data->pos.zoom * 0.2;
	if (((mouse_code == 4 || mouse_code == 1) && (y < HEIGHT / 2))
		|| (mouse_code == 5 && y > HEIGHT / 2))
		data->pos.y -= data->pos.zoom * 0.2;
	if (((mouse_code == 4 || mouse_code == 1) && (y > HEIGHT / 2))
		|| (mouse_code == 5 && y < HEIGHT / 2))
		data->pos.y += data->pos.zoom * 0.2;
	iterate_screen(data);
	return (mouse_code);
}
