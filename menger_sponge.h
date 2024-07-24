/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menger_sponge.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:53:13 by dansanc3          #+#    #+#             */
/*   Updated: 2024/07/24 22:08:46 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENGER_SPONGE_H
# define MENGER_SPONGE_H
# include <stdlib.h>

typedef struct
{
	float	x;
	float	y;
	float	z;
}	Point3D;

typedef struct
{
	int	x;
	int	y;
}	Point2D;

typedef struct
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	Texture;


typedef struct{
	void	*mlx;
	void	*win;
}	t_vars;

Point2D	project(Point3D p);
Texture	load_texture(void *mlx, char *path);
void	draw_cube(Point3D origin, float size, void *mlx, void *win, Texture *texture);
void	draw_textured_face(Point3D vertices[4], void *mlx, void *win, Texture *texture);
int		is_visible(Point3D camera, Point3D v1, Point3D v2, Point3D v3);

//window config
int close_on_escape(int keycode, t_vars *vars);
int close_on_button(t_vars *vars);

#endif
