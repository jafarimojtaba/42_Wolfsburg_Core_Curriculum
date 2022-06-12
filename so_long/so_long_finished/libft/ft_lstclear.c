/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:18:03 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/11 21:00:24 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Deletes and frees the given element and every successor of that element,
	using the function ’del’ and free(3). Finally, the pointer to the list
	must be set to NULL.
RETURN VALUE
	None.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*lst_p;
	t_list	*next;

	lst_p = *lst;
	while (lst_p != 0)
	{
		next = lst_p->next;
		ft_lstdelone(lst_p, del);
		lst_p = next;
	}
	*lst = 0;
}
