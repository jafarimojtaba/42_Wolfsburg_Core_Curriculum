/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:22:59 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/27 23:33:05 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa2(t_list *stack_a)
{
	int	temp;

	if (ft_lstsize(stack_a) < 2)
		return ;
	temp = stack_a->next->content;
	stack_a->next->content = stack_a->content;
	stack_a->content = temp;
}

void	sb2(t_list *stack_b)
{
	int	temp;

	if (ft_lstsize(stack_b) < 2)
		return ;
	temp = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = temp;
}

void	ss2(t_list *stack_a, t_list *stack_b)
{
	int	temp;
	int	temp_b;

	if (ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b) < 2)
		return ;
	temp = stack_a->next->content;
	stack_a->next->content = stack_a->content;
	stack_a->content = temp;
	temp_b = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = temp_b;
}

void	pa2(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) == 0)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	pb2(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) == 0)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}
