/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:38:54 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:23 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_how_many_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	ft_find_next(char const *s, char c, int i, int find_start)
{
	if (find_start)
	{
		while (s[i] == c && s[i])
			i++;
	}
	else
	{
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}

static void	ft_free_array(char **array, int i)
{
	while (--i >= 0)
		free(array[i]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		words;
	int		start;
	int		end;

	words = ft_how_many_words(s, c);
	array = (char **) malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	i = 0;
	end = 0;
	while (i < words)
	{
		start = ft_find_next(s, c, end, 1);
		end = ft_find_next(s, c, start, 0);
		array[i] = ft_substr(s, start, end - start);
		if (!array[i++])
		{
			ft_free_array(array, i);
			return (NULL);
		}
	}
	array[i] = (void *) 0;
	return (array);
}
