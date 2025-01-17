/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:39:07 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/16 16:09:20 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error(int erro)
{
	if (erro == 1)
		ft_printf("Message 1\n");
	if (erro == 2)
		ft_printf("Message 2\n");
	if (erro == 3)
		ft_printf("Message 3\n");
	if (erro == 4)
		ft_printf("Message 4\n");
	if (erro == 5)
		ft_printf("Message 5\n");
	exit (1);
}
