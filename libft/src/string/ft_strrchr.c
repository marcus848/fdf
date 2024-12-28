/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:32:54 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:24 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len_s;

	str = (char *) s;
	len_s = ft_strlen(s) - 1;
	if ((char) c == '\0')
		return (str + len_s + 1);
	while (len_s >= 0)
	{
		if (str[len_s] == (char)c)
			return (&str[len_s]);
		len_s--;
	}
	return (NULL);
}
