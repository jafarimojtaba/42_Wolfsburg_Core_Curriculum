/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:14:37 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/27 04:50:38 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	a_sorted(t_list *stack_x)
{
	t_list	*temp;
	int		i;

	temp = stack_x;
	i = ft_lstsize(stack_x);
	while (i-- > 1)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int	b_sorted(t_list *stack_x)
{
	t_list	*temp;
	int		i;

	temp = stack_x;
	i = ft_lstsize(stack_x);
	if (i == 1)
		return (0);
	while (i > 1)
	{
		if (temp->content > temp->next->content)
			temp = temp->next;
		else
			return (0);
		i--;
	}
	return (1);
}

int	check_end(t_list *stack_a, t_list *stack_b, int i)
{
	if (ft_lstsize(stack_a) == i)
		if (ft_lstsize(stack_b) == 0)
			if (a_sorted(stack_a) == 1)
				return (1);
	return (0);
}

/*
** check if top of stack a is smaller than all numbers in stack b 
*/
int	top_a_les_b(t_list *stack_a, t_list *stack_b)
{
	while (stack_b)
	{
		if (stack_a->content < stack_b->content)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}
