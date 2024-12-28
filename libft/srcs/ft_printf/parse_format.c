/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:52:44 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:37:35 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(const char *format, t_list **lst_tokens)
{
	t_spec	*spec;
	int		i;

	spec = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
			{
				spec = parse_specifier(format, &i);
				if (spec)
					ft_lstadd_back(lst_tokens, ft_lstnew(spec));
			}
		}
		i++;
	}
}

t_spec	*parse_specifier(const char *format, int *i)
{
	t_spec	*spec;

	spec = malloc(sizeof(t_spec));
	if (!spec)
		return (NULL);
	initialize_specifier(spec);
	parse_flags(format, i, spec);
	parse_width(format, i, spec);
	parse_precision(format, i, spec);
	parse_conversion(format, i, spec);
	return (spec);
}

void	initialize_specifier(t_spec *spec)
{
	spec->conversion = 0;
	spec->flag_minus = 0;
	spec->flag_zero = 0;
	spec->flag_hash = 0;
	spec->flag_space = 0;
	spec->flag_plus = 0;
	spec->width = 0;
	spec->precision = 0;
	spec->is_precision_specified = 0;
}
