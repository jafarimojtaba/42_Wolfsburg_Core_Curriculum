/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:12:50 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/27 14:27:40 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Counts the number of elements in a list.
RETURN VALUE
	Length of the list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	if (lst != 0)
	{
		while (lst != 0)
		{
			lst = lst->next;
			len++;
		}
	}
	return (len);
}
