/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:35:24 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:37:35 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_list	*lst_tokens;
	va_list	args;
	int		length;

	length = 0;
	va_start(args, format);
	lst_tokens = NULL;
	parse_format(format, &lst_tokens);
	length += print_format(format, lst_tokens, args);
	free_specifiers(lst_tokens);
	va_end(args);
	return (length);
}
