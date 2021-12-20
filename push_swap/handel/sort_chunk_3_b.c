/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_3_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:18:27 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/30 00:02:00 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_chunk_3_b(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	th;

	f = (*stack_b)->content;
	s = (*stack_b)->next->content;
	th = (*stack_b)->next->next->content;
	if (f < s && f < th && s < th)
	{
		rb(stack_b);
		sb(*stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		rrb(stack_b);
		pa(stack_a, stack_b);
	}
	else
		sort_chunk_3_b2(stack_a, stack_b);
}

void	sort_chunk_3_b2(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	th;

	f = (*stack_b)->content;
	s = (*stack_b)->next->content;
	th = (*stack_b)->next->next->content;
	if (f < s && f < th && s > th)
	{
		rb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		rrb(stack_b);
		pa(stack_a, stack_b);
	}
	else
		sort_chunk_3_b3(stack_a, stack_b);
}

void	sort_chunk_3_b3(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	th;

	f = (*stack_b)->content;
	s = (*stack_b)->next->content;
	th = (*stack_b)->next->next->content;
	if (f < s && f > th && s > th)
	{
		sb(*stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
		sort_chunk_3_b4(stack_a, stack_b);
}

void	sort_chunk_3_b4(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	th;

	f = (*stack_b)->content;
	s = (*stack_b)->next->content;
	th = (*stack_b)->next->next->content;
	if (f > s && f > th && s > th)
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (f > s && f > th && s < th)
	{
		pa(stack_a, stack_b);
		sb(*stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
		sort_chunk_3_b5(stack_a, stack_b);
}

void	sort_chunk_3_b5(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	th;

	f = (*stack_b)->content;
	s = (*stack_b)->next->content;
	th = (*stack_b)->next->next->content;
	if (f > s && f < th && s < th)
	{
		rb(stack_b);
		sb(*stack_b);
		pa(stack_a, stack_b);
		rrb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
