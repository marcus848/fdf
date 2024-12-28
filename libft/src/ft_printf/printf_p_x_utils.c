/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p_x_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:51:19 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:37:36 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

char	*convert_to_hex(unsigned long value, int uppercase)
{
	unsigned long	tmp;
	char			*hex_digits;
	char			*result;
	int				len;

	hex_digits = hex_uppercase(uppercase);
	tmp = value / 16;
	len = 1;
	while (tmp > 0)
	{
		len++;
		tmp /= 16;
	}
	result = (char *) malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len > 0)
	{
		result[--len] = hex_digits[value % 16];
		value /= 16;
	}
	return (result);
}

char	*hex_uppercase(int uppercase)
{
	if (uppercase)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

int	print_null_pointer(t_spec *spec)
{
	int	length;

	if (spec->width > 5 && !spec->flag_minus)
		length = print_width_padding(spec->width - 5, ' ');
	else
		length = 0;
	ft_putstr_fd("(nil)", 1);
	length += 5;
	if (spec->width > 5 && spec->flag_minus)
		length += print_width_padding(spec->width - 5, ' ');
	return (length);
}

char	*add_precision_hex(t_spec *spec, char *str_hex)
{
	char	*padding;
	char	*result;
	int		str_len;

	str_len = ft_strlen(str_hex);
	if (spec->is_precision_specified && spec->precision == 0
		&& ft_strncmp(str_hex, "0", str_len) == 0)
		return (ft_strdup(""));
	if (spec->precision <= str_len)
		return (str_hex);
	padding = malloc(spec->precision - str_len + 1);
	if (!padding)
	{
		free(str_hex);
		return (NULL);
	}
	ft_memset(padding, '0', spec->precision - str_len);
	padding[spec->precision - str_len] = '\0';
	result = ft_strjoin(padding, str_hex);
	free(str_hex);
	free(padding);
	return (result);
}
