/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 22:46:04 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/12 15:51:51 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	head = new;
	while (lst->next)
	{
		lst = lst->next;
		new = ft_lstnew(f(lst->content));
		if (!new)
			ft_lstclear(&head, del);
		ft_lstadd_back(&head, new);
		new = new->next;
	}
	return (head);
}
