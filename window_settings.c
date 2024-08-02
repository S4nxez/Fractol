/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:04:00 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/02 19:11:36 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

// Función para cerrar la ventana al presionar Escape
int	close_on_escape(int keycode, t_vars *vars)
{
	if (keycode == 65307) // Escape
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

// Función para cerrar la ventana al usar el botón de cerrar
int	close_on_button(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
