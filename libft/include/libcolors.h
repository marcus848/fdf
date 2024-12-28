/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcolors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:06:22 by marcudos          #+#    #+#             */
/*   Updated: 2024/11/26 12:00:11 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCOLORS_H
# define LIBCOLORS_H

// Definindo cores ANSI como macros
# define RESET "\033[0m"

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"

// Cores de fundo
# define BG_BLACK "\033[1;40m"
# define BG_RED "\033[1;41m"
# define BG_GREEN "\033[1;42m"
# define BG_YELLOW "\033[1;43m"
# define BG_BLUE "\033[1;44m"
# define BG_MAGENTA "\033[1;45m"
# define BG_CYAN "\033[1;46m"
# define BG_WHITE "\033[1;47m"

#endif // !LIBCOLORS_H
