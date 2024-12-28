/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:36:59 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:23 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		len_s;

	len_s = ft_strlen(s);
	new_str = (char *) malloc((len_s + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s, len_s);
	new_str[len_s] = '\0';
	return (new_str);
}
