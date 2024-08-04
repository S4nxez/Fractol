/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:54:12 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/04 20:35:41 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>

# define WIDTH	600
# define HEIGHT	600

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

void	draw_mandelbrot(void *mlx_ptr, void *mlx_win, int x, int y);
int		on_keypress(int keysym, t_data *data);
int		close_on_escape(t_data *data);

#endif