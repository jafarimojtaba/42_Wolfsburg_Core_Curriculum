/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:53:12 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/11 20:59:28 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Takes as a parameter an element and frees the memory of the element’s
	content using the function ’del’ given as a parameter and free the element.
	The memory of ’next’ must not be freed.
RETURN VALUE
	None.
*/

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst != 0 && del != 0)
	{
		(*del)(lst->content);
		free(lst);
	}
}
