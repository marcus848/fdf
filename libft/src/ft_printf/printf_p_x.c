/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:47:12 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:37:36 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(t_spec *spec, va_list args)
{
	unsigned long	address;
	void			*ptr;
	char			*hex_str;
	int				length;

	ptr = (void *) va_arg(args, void *);
	if (!ptr)
		return (print_null_pointer(spec));
	address = (unsigned long) ptr;
	hex_str = convert_to_hex(address, 0);
	if (!hex_str)
		return (0);
	length = print_pointer_with_width(spec, hex_str);
	free(hex_str);
	return (length);
}

int	print_pointer_with_width(t_spec *spec, char *hex_str)
{
	int	length;
	int	hex_len;

	hex_len = ft_strlen(hex_str) + 2;
	length = 0;
	if (spec->width > hex_len && !spec->flag_minus)
		length += print_width_padding(spec->width - hex_len, ' ');
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hex_str, 1);
	length += hex_len;
	if (spec->width > hex_len && spec->flag_minus)
		length += print_width_padding(spec->width - hex_len, ' ');
	return (length);
}

int	print_hex(t_spec *spec, va_list args)
{
	unsigned int	i;
	char			*hex_str;
	int				length;

	i = va_arg(args, unsigned int);
	if (spec->conversion == 'x')
		hex_str = convert_to_hex((unsigned long) i, 0);
	else
		hex_str = convert_to_hex((unsigned long) i, 1);
	hex_str = add_precision_hex(spec, hex_str);
	length = print_hex_with_width(spec, hex_str);
	free (hex_str);
	return (length);
}

int	print_hex_with_width(t_spec *spec, char *hex_str)
{
	int	length;

	length = ft_strlen(hex_str);
	if (spec->flag_hash && ft_strncmp(hex_str, "0", length))
		length += 2;
	if (spec->width > length && !spec->flag_minus
		&& (!spec->flag_zero || spec->is_precision_specified))
		length += print_width_padding(spec->width - length, ' ');
	if (spec->flag_hash && ft_strncmp(hex_str, "0", length))
	{
		if (spec->conversion == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
	}
	if (spec->width > length && spec->flag_zero && !spec->flag_minus)
		length += print_width_padding(spec->width - length, '0');
	ft_putstr_fd(hex_str, 1);
	if (spec->width > length && spec->flag_minus)
		length += print_width_padding(spec->width - length, ' ');
	return (length);
}
