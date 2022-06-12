/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:13:36 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/27 14:26:14 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Returns the last element of the list.
RETURN VALUE
	Last element of the list.
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != 0)
	{
		while (lst->next != 0)
			lst = lst->next;
	}
	return (lst);
}
