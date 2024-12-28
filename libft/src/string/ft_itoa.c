/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:01:20 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:23 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_how_many_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_make_str(char *str, long num, int digits)
{
	while (num)
	{
		str[digits--] = num % 10 + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		digits;

	num = n;
	digits = ft_how_many_digits(n);
	str = (char *) malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits--] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	ft_make_str(str, num, digits);
	return (str);
}
