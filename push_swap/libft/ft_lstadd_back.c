/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:15:12 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/27 14:22:59 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Adds the element ’new’ at the end of the list.
RETURN VALUE
	None.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last == 0)
		*lst = new;
	else
		last->next = new;
}
