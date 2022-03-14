/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:15:51 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/11 21:10:06 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Iterates the list ’lst’ and applies the function ’f’ to the content of
	each element. Creates a new list resulting of the successive applications
	of the function ’f’. The ’del’ function is used to delete the content
	of an element if needed.
RETURN VALUE
	The new list. NULL if the allocation fails.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !f)
		return (NULL);
	new_elem = ft_lstnew(f(lst->content));
	if (!new_elem)
		return (NULL);
	new_list = new_elem;
	while (lst->next)
	{
		lst = lst->next;
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, new_elem);
	}
	return (new_list);
}
