/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:58:24 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:24 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len + start > str_len)
		len = str_len - start;
	sub_s = (char *) malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	ft_memcpy(sub_s, &s[start], len);
	sub_s[len] = '\0';
	return (sub_s);
}
