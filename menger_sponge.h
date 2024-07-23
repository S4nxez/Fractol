#ifndef MENGER_SPONGE_H
#define MENGER_SPONGE_H
#include <stdlib.h>

typedef struct {
    float x, y, z;
} Point3D;

typedef struct {
    int x, y;
} Point2D;

typedef struct {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int width;
    int height;
} Texture;

Point2D project(Point3D p);
void draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1);
void draw_cube(Point3D origin, float size, void *mlx, void *win, Texture *texture);
Texture load_texture(void *mlx, char *path);
void draw_textured_face(Point3D vertices[4], void *mlx, void *win, Texture *texture);
int is_visible(Point3D camera, Point3D v1, Point3D v2, Point3D v3);

#endif
