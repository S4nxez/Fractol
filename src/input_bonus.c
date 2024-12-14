/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:33:26 by dansanc3          #+#    #+#             */
/*   Updated: 2024/12/13 16:51:57 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	input_validator(void)
{
	char	*entrada;
	int		ret;

	ft_printf("Selecciona el fractal: \n1.Mandelbrot\n2.Julia\n3.Newton\n");
	ret = 0;
	while (ret == 0)
	{
		entrada = get_next_line(1);
		if (!entrada)
			return (1);
		if ((*entrada < '1' || *entrada > '3') || entrada[1] != '\n')
		{
			ft_printf("Entrada no válida, introduce una opción del 1 al 3\n");
		}
		else
			ret = *entrada - '0';
		free(entrada);
	}
	return (ret);
}
