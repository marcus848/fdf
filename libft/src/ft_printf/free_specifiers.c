/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_specifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:13:17 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:37:35 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_specifiers(t_list *lst_tokens)
{
	ft_lstclear(&lst_tokens, del_specifier);
}

void	del_specifier(void *content)
{
	t_spec	*spec;

	spec = (t_spec *)content;
	if (spec)
		free(spec);
}
