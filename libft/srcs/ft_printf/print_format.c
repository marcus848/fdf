/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:24:19 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:37:35 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(const char *format, t_list *lst_tokens, va_list args)
{
	t_list	*current_token;
	int		i;
	int		length;

	i = 0;
	length = 0;
	current_token = lst_tokens;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (current_token)
			{
				length += process_token((t_spec *)current_token->content, args);
				current_token = current_token->next;
			}
			i = next_letter(format, i);
		}
		else
		{
			length += write_plain_text(format, &i, 1);
		}
	}
	return (length);
}

int	process_token(t_spec *spec, va_list args)
{
	if (spec->conversion == 'c')
		return (print_char(spec, args));
	else if (spec->conversion == 's')
		return (print_string(spec, args));
	else if (spec->conversion == 'p')
		return (print_pointer(spec, args));
	else if (spec->conversion == 'x' || spec->conversion == 'X')
		return (print_hex(spec, args));
	else if (spec->conversion == 'd' || spec->conversion == 'i')
		return (print_integer(spec, args));
	else if (spec->conversion == '%')
		return (print_percent(spec));
	else if (spec->conversion == 'u')
		return (print_unsigned(spec, args));
	return (0);
}

int	next_letter(const char *format, int i)
{
	while (format[i] && !ft_strchr(SPECIFIERS, format[i]))
		i++;
	if (ft_strchr(SPECIFIERS, format[i]))
		i++;
	return (i);
}

int	write_plain_text(const char *format, int *i, int fd)
{
	int	length;

	length = 0;
	while (format[*i] && format[*i] != '%')
	{
		ft_putchar_fd(format[*i], fd);
		length++;
		(*i)++;
	}
	return (length);
}
