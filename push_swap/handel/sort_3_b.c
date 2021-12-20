/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:34:08 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/29 16:51:46 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3_b(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	th;

	while (!b_sorted(*stack_b))
	{
		f = (*stack_b)->content;
		s = (*stack_b)->next->content;
		th = (*stack_b)->next->next->content;
		if (f < s && f < th && s < th)
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
			sb(*stack_b);
		}
		if (f < s && f < th && s > th)
			rb(stack_b);
		if (f < s && f > th && s > th)
			sb(*stack_b);
		sort_3_b2(stack_a, stack_b);
	}
}

void	sort_3_b2(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	th;

	while (!b_sorted(*stack_b))
	{
		f = (*stack_b)->content;
		s = (*stack_b)->next->content;
		th = (*stack_b)->next->next->content;
		if (f > s && f > th && s < th)
		{
			pa(stack_a, stack_b);
			sb(*stack_b);
		}
		if (f > s && f < th && s < th)
			rrb(stack_b);
	}
}
