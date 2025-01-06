/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:14:29 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/06 16:32:17 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../mlx/mlx.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"
#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280
#define WINDOW_NAME "teste"

typedef struct s_env {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_env;

int key_handler(int keycode, t_env *env);
int mouse_handler(int mousecode, int x, int y, t_env *env);
int render(t_env *env);
int close_window(int keycode, t_env *env);
void draw_background(t_env *env);
void draw_player(t_env *env);
void draw_moves(t_env *env);
void draw_map(t_env *env);

int main(void)
{
/* 
 * this is the MLX initialisation, I only put it in the example so you can
 * better see what I am doing below
 */
    t_env env;

    env.mlx = mlx_init();
    env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    env.img = mlx_new_image(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, &env.line_length, &env.endian);
     /* end of MLX initialisation */
     /* Here I will be declaring the hooks, see below for their implementation.
     */
     mlx_hook(env.win, 4, 0, mouse_handler, &env);
     // mouse_handler will be called everytime a mouse down event is emitted
     mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
     // key_handler will be called everytime a key is pressed
     mlx_hook(env.win, 17, 1L << 0, close_window, &env);
     // close_window is called when we click on the red cross to close the window
     mlx_loop_hook(env.mlx, render, &env);
     // Since MXL loops over and over again, we can use the mlx_loop_hook
     // to execute a function everytime MLX loops over.
     
     mlx_loop(env.mlx);
}

int key_handler(int keycode, t_env *env)
{
    if (keycode == 53)
        ft_printf("ESCAPE");
    else if (keycode == 0 || keycode == 123)
        ft_printf("LEFT (A / ARROW_LEFT)");
    else if (keycode == 2 || keycode == 124)
        ft_printf("RIGHT (D / ARROW_RIGHT)");
    else if (keycode == 1 || keycode == 125)
        ft_printf("DOWN (S / ARROW_DOWN)");
    else if (keycode == 13 || keycode == 126)
        ft_printf("LEFT (A / ARROW_LEFT)");
    else
        ft_printf("%d\n", keycode);
    return (0);
}

int mouse_handler(int mousecode, int x, int y, t_env *env)
{
    /* x and y parameters are the pixel coordinates of the mouse
     * in the window when the event was emitted
     * you can use them to check that the user clicked in a specific region
     * of the window
     */
     if (mousecode == 1)
         ft_printf("Left Click");
     else if (mousecode == 2)
         ft_printf("Right Click");
     else if (mousecode == 3)
         ft_printf("Middle Click");
     else if (mousecode == 4)
         ft_printf("Scroll UP");
     else if (mousecode == 5)
         ft_printf("Scroll DOWN");
     else if (mousecode == 6)
         ft_printf("Scroll right");
     else if (mousecode == 7)
         ft_printf("Scroll left");
     else
         ft_printf("%d\n", mousecode);
	return (0);
}

int close_window(int keycode, t_env *env)
{
    if (keycode == 53) // ESC
    {
        mlx_destroy_window(env->mlx, env->win);
        exit(0);  // Fecha o programa
    }
    return 0;
}


int render(t_env *env)
{
    draw_background(env);
    draw_map(env);
    draw_player(env);
    draw_moves(env);
	return 0;
}

void draw_background(t_env *env)
{
    // Supondo que você desenhe um fundo simples preenchendo a tela com uma cor
    int i = 0;
    while (i < WINDOW_HEIGHT * WINDOW_WIDTH)
    {
        env->addr[i * (env->bits_per_pixel / 8)] = 0;       // Red
        env->addr[i * (env->bits_per_pixel / 8) + 1] = 0;   // Green
        env->addr[i * (env->bits_per_pixel / 8) + 2] = 0;   // Blue
        env->addr[i * (env->bits_per_pixel / 8) + 3] = 0;   // Alpha (0 = transparente, 255 = opaco)
        i++;
    }
}

void draw_player(t_env *env)
{
    int player_x = 5;  // Posição do jogador no eixo X
    int player_y = 5;  // Posição do jogador no eixo Y
    int player_radius = 20;  // Raio do jogador (representado por um círculo)
    int color = 0xFF0000;  // Cor vermelha para o jogador
    int x, y;

    for (y = -player_radius; y <= player_radius; y++)
    {
        for (x = -player_radius; x <= player_radius; x++)
        {
            if (x * x + y * y <= player_radius * player_radius)  // Verifica se o pixel está dentro do círculo
            {
                mlx_pixel_put(env->mlx, env->win, player_x * 64 + x, player_y * 64 + y, color);
            }
        }
    }
}

void draw_moves(t_env *env)
{
    static int move_count = 0;
    char *move_text;

    move_count++;  // Incrementa o contador de movimentos

    // Cria a string para mostrar o número de movimentos
    move_text = ft_strjoin("Movimentos: ", ft_itoa(move_count));

    // Exibe a string no topo da janela (cuidado com a posição)
    mlx_string_put(env->mlx, env->win, 10, 10, 0xFFFFFF, move_text);

    // Libere a memória alocada para o texto
    free(move_text);
}


void draw_map(t_env *env)
{
    int map[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int cell_size = 64;  // Tamanho de cada célula do mapa
    int x, y;

    for (y = 0; y < 9; y++)  // Limite de altura do mapa (10 células)
    {
        for (x = 0; x < 10; x++)  // Limite de largura do mapa (10 células)
        {
            int color;

            if (map[y][x] == 1)
                color = 0xFFFFFF;  // Cor branca para paredes
            else
                color = 0x00FF00;  // Cor verde para espaços vazios

            // Preenche cada célula com a cor
            mlx_pixel_put(env->mlx, env->win, x * cell_size, y * cell_size, color);
        }
    }
}

