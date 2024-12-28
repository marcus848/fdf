/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:38:20 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:24 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verify_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_find_start(char const *s1, char const *set)
{
	int	i_s1;

	i_s1 = 0;
	while (s1[i_s1])
	{
		if (!ft_verify_set(s1[i_s1], set))
			return (i_s1);
		i_s1++;
	}
	return (i_s1);
}

static int	ft_find_end(char const *s1, char const *set)
{
	int	len_s1;

	len_s1 = ft_strlen(s1) - 1;
	while (len_s1 >= 0)
	{
		if (!ft_verify_set(s1[len_s1], set))
			return (len_s1);
		len_s1--;
	}
	return (len_s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	int		i_start;
	int		i_end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	i_start = ft_find_start(s1, set);
	i_end = ft_find_end(s1, set);
	if (i_start > i_end)
		return (ft_strdup(""));
	str_trim = (char *) malloc((i_end - i_start + 2) * sizeof(char));
	if (!str_trim)
		return (NULL);
	ft_strlcpy(str_trim, &s1[i_start], i_end - i_start + 2);
	return (str_trim);
}
