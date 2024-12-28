/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:00:09 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:37:35 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char *format, int *i, t_spec *spec)
{
	while (ft_strchr(FLAGS, format[*i]))
	{
		if (format[*i] == '-')
			spec->flag_minus = 1;
		else if (format[*i] == '0')
			spec->flag_zero = 1;
		else if (format[*i] == '#')
			spec->flag_hash = 1;
		else if (format[*i] == ' ')
			spec->flag_space = 1;
		else if (format[*i] == '+')
			spec->flag_plus = 1;
		*i += 1;
	}
}

void	parse_width(const char *format, int *i, t_spec *spec)
{
	spec->width = ft_atoi(&format[*i]);
	if (spec->width)
	{
		while (format[*i] >= '0' && format[*i] <= '9')
			*i += 1;
	}
}

void	parse_precision(const char *format, int *i, t_spec *spec)
{
	if (format[*i] == '.')
	{
		spec->is_precision_specified = 1;
		*i += 1;
		spec->precision = ft_atoi(&format[*i]);
		while (format[*i] >= '0' && format[*i] <= '9')
			*i += 1;
	}
}

void	parse_conversion(const char *format, int *i, t_spec *spec)
{
	if (ft_strchr(SPECIFIERS, format[*i]))
		spec->conversion = format[*i];
}
