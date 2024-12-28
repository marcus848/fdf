/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_i_d_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:18:40 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:37:35 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(t_spec *spec, va_list args)
{
	char	*nbr_str;
	int		nbr;
	int		length;

	nbr = va_arg(args, int);
	nbr_str = convert_to_str(nbr, spec);
	if (!nbr_str)
		return (0);
	length = print_integer_with_width(spec, nbr, nbr_str);
	free(nbr_str);
	return (length);
}

int	print_integer_with_width(t_spec *spec, long nbr, char *nbr_str)
{
	char	*sign;
	int		length;
	int		total_len;

	sign = define_sign_or_space(spec, nbr);
	total_len = ft_strlen(nbr_str);
	if (sign)
		total_len++;
	length = 0;
	if (spec->width > total_len && !spec->flag_minus
		&& (!spec->flag_zero || spec->is_precision_specified))
		length += print_width_padding(spec->width - total_len, ' ');
	if (sign)
	{
		ft_putstr_fd(sign, 1);
		length++;
	}
	if (spec->flag_zero && !spec->flag_minus && !spec->is_precision_specified)
		length += print_width_padding(spec->width - total_len, '0');
	ft_putstr_fd(nbr_str, 1);
	length += ft_strlen(nbr_str);
	if (spec->width > total_len && spec->flag_minus)
		length += print_width_padding(spec->width - total_len, ' ');
	return (length);
}

int	print_unsigned(t_spec *spec, va_list args)
{
	unsigned int	nbr;
	char			*nbr_str;
	int				length;

	nbr = va_arg(args, unsigned int);
	nbr_str = convert_to_str(nbr, spec);
	if (!nbr_str)
		return (0);
	length = print_integer_with_width(spec, nbr, nbr_str);
	free(nbr_str);
	return (length);
}
