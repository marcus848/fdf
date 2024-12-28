/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:18:15 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/20 14:51:07 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libs.h"
# include "ft_string.h"
# include "ft_memory.h"

char	*get_next_line(int fd);
char	*find_next_line(char *line);
char	*find_current_line(char *line);
char	*get_full_line(int fd, char *line);

#endif
