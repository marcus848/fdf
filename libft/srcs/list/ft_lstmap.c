/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:11:32 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/17 20:36:23 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current_original;
	t_list	*current_new;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (NULL);
	current_original = lst->next;
	current_new = new_list;
	while (current_original)
	{
		current_new->next = ft_lstnew(f(current_original->content));
		if (!current_new->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		current_new = current_new->next;
		current_original = current_original->next;
	}
	return (new_list);
}
