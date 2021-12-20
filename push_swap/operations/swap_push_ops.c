/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:22:59 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/27 23:33:33 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list *stack_a)
{
	int	temp;

	if (ft_lstsize(stack_a) < 2)
		return ;
	temp = stack_a->next->content;
	stack_a->next->content = stack_a->content;
	stack_a->content = temp;
	write(1, "sa\n", 3);
}

void	sb(t_list *stack_b)
{
	int	temp;

	if (ft_lstsize(stack_b) < 2)
		return ;
	temp = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = temp;
	write(1, "sb\n", 3);
}

void	ss(t_list *stack_a, t_list *stack_b)
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
	write(1, "ss\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) == 0)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) == 0)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}
