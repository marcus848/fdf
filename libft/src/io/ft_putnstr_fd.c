/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:19:34 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:22 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char *s, size_t n, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && i < n)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
