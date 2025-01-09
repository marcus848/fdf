#include "../include/fdf.h"

void    render_next_frame(void *mlx)
{
    static int color = 0;

    if (color == 0)
        mlx_clear_window(mlx, mlx_get_window(mlx));
        mlx_string_put(mlx, mlx_get_window(mlx), 50, 50, 0xFF0000, "Vermelho!");
    }
    else if (color == 1)
        mlx_clear_window(mlx, mlx_get_window(mlx));
        mlx_string_put(mlx, mlx_get_window(mlx), 50, 50, 0x00FF00, "Verde!");
    }
    else if (color == 2)
        mlx_clear_window(mlx, mlx_get_window(mlx));
        mlx_string_put(mlx, mlx_get_window(mlx), 50, 50, 0x0000FF, "Azul!");
    }
}

int main()
{
    void *mlx;

    mlx = mlx_init();
    mlx_loop_hook(mlx, render_next_frame, mlx);
    mlx_loop(mlx);
    return 0;
}

