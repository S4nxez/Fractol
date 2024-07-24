/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:49:02 by dansanc3          #+#    #+#             */
/*   Updated: 2024/07/24 22:24:37 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "menger_sponge.h"


int	main(void)
{
	Texture	texture;
	Point3D	origin = {-0.5, -0.5, -0.5};
	float	size;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "Menger Sponge");
/*
    // Hook para escuchar las teclas
    mlx_key_hook(vars.win, close_on_escape, &vars);
    // Hook para cerrar la ventana con el botón de cerrar
    mlx_hook(vars.win, 17, 0, close_on_button, &vars);
    // Loop principal de eventos
    mlx_loop(vars.mlx);
*/
	texture = load_texture(vars.mlx, "texturaTemporal.xpm");
	size = 1.0;
	draw_cube(origin, size, vars.mlx, vars.win, &texture);
	mlx_loop(vars.mlx);
	return (0);
}


