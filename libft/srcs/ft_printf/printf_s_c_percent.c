/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s_c_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:56:24 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:37:36 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_spec *spec, va_list args)
{
	char	c;
	int		width;
	int		length;

	c = (char) va_arg(args, int);
	width = spec->width;
	length = 0;
	if (spec->flag_minus)
	{
		ft_putchar_fd(c, 1);
		length++;
		length += print_width_padding(width - 1, ' ');
	}
	else
	{
		length += print_width_padding(width - 1, ' ');
		ft_putchar_fd(c, 1);
		length++;
	}
	return (length);
}

int	print_string(t_spec *spec, va_list args)
{
	char	*str;
	int		length;
	int		str_len;

	str = (char *) va_arg(args, char *);
	if (!str)
		str = make_null_string(spec);
	str_len = ft_strlen(str);
	if (spec->is_precision_specified && spec->precision < str_len)
		str_len = spec->precision;
	length = 0;
	if (spec->width > str_len && !spec->flag_minus)
		length += print_width_padding(spec->width - str_len, ' ');
	ft_putnstr_fd(str, str_len, 1);
	length += str_len;
	if (spec->width > str_len && spec->flag_minus)
		length += print_width_padding(spec->width - str_len, ' ');
	return (length);
}

int	print_percent(t_spec *spec)
{
	if (spec->conversion == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

char	*make_null_string(t_spec *spec)
{
	if (spec->is_precision_specified && spec->precision < 5)
		return ("");
	else
		return ("(null)");
}
