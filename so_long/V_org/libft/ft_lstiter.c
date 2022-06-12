/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:54:13 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/11 21:01:58 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Iterates the list ’lst’ and applies the function ’f’ to the content
	of each element.
RETURN VALUE
	None.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst != 0 && f != 0)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
