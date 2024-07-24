// menger_sponge.c

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

void draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        mlx_pixel_put(mlx, win, x0, y0, 0xFFFFFF);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
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

    int edges[12][2] = {
        {0, 1}, {1, 3}, {3, 2}, {2, 0},
        {4, 5}, {5, 7}, {7, 6}, {6, 4},
        {1, 4}, {0, 5}, {2, 7}, {3, 6}
    };

    int faces[6][4] = {
        {0, 1, 2, 3}, // Cara frontal
        {4, 5, 6, 7}, // Cara trasera
        {0, 1, 5, 4}, // Cara inferior
        {2, 3, 7, 6}, // Cara superior
        {1, 4, 3, 6}, // Cara derecha
        {5, 0, 7, 2}  // Cara izquierda
    };

    for (int i = 0; i < 12; i++) {
        Point2D p0 = project(vertices[edges[i][0]]);
        Point2D p1 = project(vertices[edges[i][1]]);
        draw_line(mlx, win, p0.x, p0.y, p1.x, p1.y);
    }

    Point3D camera = {0, 0, -1}; // Posición de la cámara

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
