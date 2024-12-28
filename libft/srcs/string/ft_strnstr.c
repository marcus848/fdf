/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:49:39 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:24 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str_b;
	size_t	l_len;

	l_len = ft_strlen(little);
	str_b = (char *) big;
	if (*little == '\0')
		return (str_b);
	while (*str_b && len >= l_len)
	{
		if (ft_strncmp(str_b, little, l_len) == 0)
			return (str_b);
		len--;
		str_b++;
	}
	return (NULL);
}
