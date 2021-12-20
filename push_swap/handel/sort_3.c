/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:30:36 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/28 19:43:09 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	f;
	int	s;
	int	l;

	while (!a_sorted(*stack_a))
	{
		f = (*stack_a)->content;
		s = (*stack_a)->next->content;
		l = ft_lstlast(*stack_a)->content;
		if (f > s && f > l && s < l)
			ra(stack_a);
		if (f > s && f > l && s > l)
		{
			sa(*stack_a);
			rra(stack_a);
		}
		if (f < s && f < l && s > l)
			ra(stack_a);
		if (f > s && f < l && s < l)
			sa(*stack_a);
		if (f < s && f > l && s > l)
			rra(stack_a);
	}
}

void	sort_chunk_3(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	th;

	while (!a_sorted(*stack_a))
	{
		f = (*stack_a)->content;
		s = (*stack_a)->next->content;
		th = (*stack_a)->next->next->content;
		if (f > s && f > th && s < th)
		{
			sa(*stack_a);
			pb(stack_a, stack_b);
			sa(*stack_a);
			pa(stack_a, stack_b);
		}
		sort_chunk_32(stack_a, stack_b);
	}
}

void	sort_chunk_32(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	th;

	while (!a_sorted(*stack_a))
	{
		f = (*stack_a)->content;
		s = (*stack_a)->next->content;
		th = (*stack_a)->next->next->content;
		if (f > s && f > th && s > th)
		{
			sa(*stack_a);
			pb(stack_a, stack_b);
			sa(*stack_a);
			pa(stack_a, stack_b);
			sa(*stack_a);
		}
		if (f < s && f < th && s > th)
		{
			pb(stack_a, stack_b);
			sa(*stack_a);
			pa(stack_a, stack_b);
		}
		sort_chunk_33(stack_a, stack_b);
	}
}

void	sort_chunk_33(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	th;

	while (!a_sorted(*stack_a))
	{
		f = (*stack_a)->content;
		s = (*stack_a)->next->content;
		th = (*stack_a)->next->next->content;
		if (f > s && f < th && s < th)
			sa(*stack_a);
		if (f < s && f > th && s > th)
		{
			pb(stack_a, stack_b);
			sa(*stack_a);
			pa(stack_a, stack_b);
			sa(*stack_a);
		}
	}
}
