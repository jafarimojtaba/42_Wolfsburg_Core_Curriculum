/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:57:38 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/29 22:45:41 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			return ;
		else
		{
			while (*lst)
			{
				tmp = *lst;
				del(tmp->content);
				*lst = tmp->next;
				free(tmp);
			}
		}
	}
}
