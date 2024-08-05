/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:04:00 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/05 23:53:07 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <stdio.h>

// Función para cerrar la ventana al presionar Escape
int	close_on_escape(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data1)
{
	t_data	*data = (t_data *)data1;

	if (keysym == 65307)
	{
		close_on_escape(data);
	}
	else
	{
		if (data->input_len < (int) sizeof(data->input) - 1)
		{
			data->input[data->input_len] = (char)keysym;
			data->input_len++;
			data->input[data->input_len] = '\0';
			printf("Pressed key: %d\n", keysym);
			fflush(stdout);
			iterate_screen(data, data->func);
		}
	}
	return (keysym);
}
