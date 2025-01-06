/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:21:19 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/20 14:49:26 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "-0#+ "
# include "libc.h"

typedef struct s_specifier
{
	char	conversion;
	int		flag_minus;
	int		flag_zero;
	int		flag_hash;
	int		flag_space;
	int		flag_plus;
	int		width;
	int		precision;
	int		is_precision_specified;
}	t_spec;

void	parse_format(const char *format, t_list **lst_tokens);
void	initialize_specifier(t_spec *spec);
void	parse_flags(const char *format, int *i, t_spec *spec);
void	parse_width(const char *format, int *i, t_spec *spec);
void	parse_precision(const char *format, int *i, t_spec *spec);
void	parse_conversion(const char *format, int *i, t_spec *spec);
void	free_specifiers(t_list *lst_tokens);
void	del_specifier(void *content);
t_spec	*parse_specifier(const char *format, int *i);
int		ft_printf(const char *format, ...);
int		next_letter(const char *format, int i);
int		print_format(const char *format, t_list *lst_tokens, va_list args);
int		process_token(t_spec *spec, va_list args);
int		write_plain_text(const char *format, int *i, int fd);
int		print_char(t_spec *spec, va_list args);
int		print_string(t_spec *spec, va_list args);
int		print_integer(t_spec *spec, va_list args);
int		print_unsigned(t_spec *spec, va_list args);
int		print_hex(t_spec *spec, va_list args);
int		print_pointer(t_spec *spec, va_list args);
int		print_percent(t_spec *spec);
// char	define_pad(t_spec *spec);
int		print_width_padding(int width, char pad_char);
char	*convert_to_hex(unsigned long value, int uppercase);
char	*hex_uppercase(int uppercase);
int		print_null_pointer(t_spec *spec);
int		print_pointer_with_width(t_spec *spec, char *hex_str);
int		print_hex_with_width(t_spec *spec, char *hex_str);
char	*define_sign_or_space(t_spec *spec, long nbr);
char	*convert_to_str(long nbr, t_spec *spec);
char	*add_precision_integer(char *nbr_str, t_spec *spec);
int		print_integer_with_width(t_spec *spec, long nbr, char *nbr_str);
char	*add_precision_hex(t_spec *spec, char *str_hex);
char	*make_null_string(t_spec *spec);

#endif // !FT_PRINTF_H
