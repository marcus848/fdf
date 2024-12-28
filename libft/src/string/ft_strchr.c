/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:38:02 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:23 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*point;
	int		i;

	point = (char *)s;
	i = 0;
	while (point[i])
	{
		if (point[i] == (char)c)
			return (&point[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&point[i]);
	return (NULL);
}
