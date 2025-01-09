/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:52:20 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/09 15:23:08 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"
typedef struct	s_data {
	void	*mlx;
	void	*win;
	int		counter;
}				t_data;

int	render_next_frame(void *data_ptr)
{
	t_data	*data = (t_data *)data_ptr;

	// Limpa a janela (opcional, dependendo da lógica)
	mlx_clear_window(data->mlx, data->win);

	// Atualiza e desenha algo (exemplo: contador na tela)
	char	str[100];
	sprintf(str, "Frame count: %d", data->counter++);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, str);

	// Retorna 0 para continuar o loop
	return (0);
}

int	main(void)
{
	t_data	data;

	// Inicializa a estrutura
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 640, 480, "mlx_loop_hook Example");
	data.counter = 0;

	// Define o loop_hook
	mlx_loop_hook(data.mlx, render_next_frame, &data);

	// Entra no loop da MiniLibX
	mlx_loop(data.mlx);
}

