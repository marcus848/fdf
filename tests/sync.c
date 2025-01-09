/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:40:37 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/09 14:47:13 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

typedef struct s_data {
    void    *img;           // Ponteiro para a imagem
    char    *addr;          // Endereço dos dados da imagem
    int     bits_per_pixel; // Bits por pixel
    int     size_line;      // Tamanho da linha (em bytes)
    int     endian;         // Endian
}           t_data;

// Função de inicialização
int init_mlx(t_data *data, void *mlx, void **window) {
    *window = mlx_new_window(mlx, 800, 600, "Sincronização MLX");
    if (!*window)
        return 1;
    
    data->img = mlx_new_image(mlx, 800, 600);
    if (!data->img)
        return 1;
    
    // Obtém o endereço dos dados da imagem
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, 
                                    &data->size_line, &data->endian);
    return 0;
}

// Função para desenhar na imagem
void draw_image(t_data *data) {
    // Desenhando a cor verde na imagem
    for (int y = 0; y < 600; y++) {
        for (int x = 0; x < 800; x++) {
            *(int *)(data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8))) = 0x00FF00; // Cor verde
        }
    }
}

int main()
{
    void    *mlx;
    void    *window;
    t_data  data;

    // Inicializando o MiniLibX
    mlx = mlx_init();
    if (!mlx) {
        printf("Erro na inicialização do mlx\n");
        return 1;
    }

    // Inicializando a janela e a imagem
    if (init_mlx(&data, mlx, &window)) {
        printf("Erro na criação da janela ou imagem\n");
        return 1;
    }

    // Desenha na imagem
    draw_image(&data);

    // Coloca a imagem na janela
    mlx_put_image_to_window(mlx, window, data.img, 0, 0);

    // Sincroniza as operações gráficas com a função mlx_do_sync
    mlx_do_sync(mlx);

    // Loop do MiniLibX (aguarda interação do usuário)
    mlx_loop(mlx);

    return 0;
}

