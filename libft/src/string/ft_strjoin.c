/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:13:14 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:24 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_res;
	int		str1_len;
	int		str2_len;

	str1_len = ft_strlen(s1);
	str2_len = ft_strlen(s2);
	str_res = (char *) malloc((str1_len + str2_len + 1) * sizeof(char));
	if (!str_res)
		return (NULL);
	ft_memcpy(str_res, s1, str1_len);
	ft_memcpy(&str_res[str1_len], s2, str2_len);
	str_res[str1_len + str2_len] = '\0';
	return (str_res);
}
