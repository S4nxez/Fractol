/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:54:12 by dansanc3          #+#    #+#             */
/*   Updated: 2024/08/09 21:38:46 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>

# define WIDTH	800
# define HEIGHT 800

typedef struct pos
{
	double	x;
	double	y;
	double	zoom;
}	t_position;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		input[256];
	int			input_len;
	void		(*func)(struct s_data *, int, int);
	t_position	pos;
}	t_data;

void	draw_mandelbrot(t_data *data, int x, int y);
int		on_keypress(int keysym, t_data *data1);
int		close_on_escape(t_data *data);
void	iterate_screen(t_data *data, void (*f)(t_data *, int, int));
#endif