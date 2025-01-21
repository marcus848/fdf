/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:00:55 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/21 20:08:45 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../mlx/mlx.h"
#include <unistd.h>
void *mlx;
void *win;
int width = 800;
int height = 600;

void resize_window(int new_width, int new_height)
{
    // Fechar a janela antiga
    mlx_destroy_window(mlx, win);

    // Criar uma nova janela com o novo tamanho
    win = mlx_new_window(mlx, new_width, new_height, "resize");
    // Atualizar o tamanho
    width = new_width;
    height = new_height;

    // Redesenhar o conteúdo da nova janela, se necessário
    mlx_string_put(mlx, win, 50, 50, 0xFFFFFF, "Nova Janela Redimensionada");
}

int main()
{
    // Inicializa a MLX
    mlx = mlx_init();

    // Cria a janela com o tamanho inicial
    win = mlx_new_window(mlx, width, height, "resize");

    // Exibe uma string na janela
    mlx_string_put(mlx, win, 50, 50, 0xFFFFFF, "Janela Original");

    // Redimensiona a janela após 5 segundos
    sleep(5); // Espera 5 segundos
    resize_window(1024, 768); // Redimensiona a janela

    // Espera até que a janela seja fechada
    mlx_loop(mlx);
    
    return 0;
}

