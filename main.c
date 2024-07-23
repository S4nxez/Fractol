// main.c

#include <mlx.h>
#include "menger_sponge.h"

int main() {
    void *mlx;
    void *win;
    Texture texture;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 800, "Menger Sponge");

    // Cargar la textura (ruta de la imagen .xpm)
    texture = load_texture(mlx, "texturaTemporal.xpm");

    Point3D origin = {-0.5, -0.5, -0.5};
    float size = 1.0;

    draw_cube(origin, size, mlx, win, &texture);

    mlx_loop(mlx);
    return 0;
}
