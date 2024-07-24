/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menger_sponge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:47:16 by dansanc3          #+#    #+#             */
/*   Updated: 2024/07/24 21:48:12 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "menger_sponge.h"
#include <math.h>

Point2D project(Point3D p) {
	Point2D projected;
	float distance = 2.0;
	float fov = 256;
	projected.x = (int)(p.x * fov / (distance - p.z) + 400);
	projected.y = (int)(p.y * fov / (distance - p.z) + 400);
	return projected;
}

Texture load_texture(void *mlx, char *path) {
	Texture texture;
	texture.img = mlx_xpm_file_to_image(mlx, path, &texture.width, &texture.height);
	if (!texture.img)
		return (texture);
	texture.addr = mlx_get_data_addr(texture.img, &texture.bits_per_pixel, &texture.line_length, &texture.endian);
	return texture;
}

int is_visible(Point3D camera, Point3D v1, Point3D v2, Point3D v3) {
	Point3D edge1 = {v2.x - v1.x, v2.y - v1.y, v2.z - v1.z};
	Point3D edge2 = {v3.x - v1.x, v3.y - v1.y, v3.z - v1.z};
	Point3D normal = {
		edge1.y * edge2.z - edge1.z * edge2.y,
		edge1.z * edge2.x - edge1.x * edge2.z,
		edge1.x * edge2.y - edge1.y * edge2.x
	};
	Point3D view = {v1.x - camera.x, v1.y - camera.y, v1.z - camera.z};
	float dot = normal.x * view.x + normal.y * view.y + normal.z * view.z;
	return (dot < 0);
}

void draw_textured_face(Point3D vertices[4], void *mlx, void *win, Texture *texture) {
	Point2D projected[4];
	for (int i = 0; i < 4; i++) {
		projected[i] = project(vertices[i]);
	}

	// Implementación básica de mapeo de texturas
	// Dibujar un rectángulo con la textura (simplificación)
	for (int y = 0; y < texture->height; y++) {
		for (int x = 0; x < texture->width; x++) {
			int color = *(int *)(texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8)));
			int screen_x = projected[0].x + (projected[1].x - projected[0].x) * x / texture->width;
			int screen_y = projected[0].y + (projected[2].y - projected[0].y) * y / texture->height;
			mlx_pixel_put(mlx, win, screen_x, screen_y, color);
		}
	}
}

void draw_cube(Point3D origin, float size, void *mlx, void *win, Texture *texture) {
	Point3D vertices[8] = {
		{origin.x, origin.y, origin.z},
		{origin.x + size, origin.y, origin.z},
		{origin.x + size, origin.y + size, origin.z},
		{origin.x, origin.y + size, origin.z},
		{origin.x, origin.y, origin.z + size},
		{origin.x + size, origin.y, origin.z + size},
		{origin.x + size, origin.y + size, origin.z + size},
		{origin.x, origin.y + size, origin.z + size}
	};

	int faces[6][4] = {
		{0, 1, 2, 3}, // Cara frontal
		{4, 5, 6, 7}, // Cara trasera
		{0, 1, 5, 4}, // Cara inferior
		{2, 3, 7, 6}, // Cara superior
		{1, 2, 6, 5}, // Cara derecha
		{0, 3, 7, 4}  // Cara izquierda
	};

	Point3D camera = {-5, -5, 0}; // Posición de la cámara

	// Dibujar las caras del cubo
	for (int i = 0; i < 6; i++) {
		Point3D face_vertices[4] = {
			vertices[faces[i][0]],
			vertices[faces[i][1]],
			vertices[faces[i][2]],
			vertices[faces[i][3]]
		};
		if (is_visible(camera, face_vertices[0], face_vertices[1], face_vertices[2]))
			draw_textured_face(face_vertices, mlx, win, texture);
	}
}

