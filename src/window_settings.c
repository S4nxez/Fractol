/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:04:00 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/27 11:34:03 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Función para cerrar la ventana al presionar Escape
int	close_on_escape(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
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
