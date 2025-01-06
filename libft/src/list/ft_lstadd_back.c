/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:03:12 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/20 14:53:11 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *lnew)
{
	t_list	*temp;

	if (!lst || !lnew)
		return ;
	if (!*lst)
	{
		*lst = lnew;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = lnew;
}
