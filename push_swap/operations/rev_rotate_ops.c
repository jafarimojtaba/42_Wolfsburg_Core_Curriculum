/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:11:36 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/26 23:45:54 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*copy;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	temp = ft_lstlast(*stack_a);
	temp->next = *stack_a;
	*stack_a = temp;
	copy = *stack_a;
	while (copy->next != temp)
		copy = copy->next;
	copy->next = 0x0;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*copy;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	temp = ft_lstlast(*stack_b);
	temp->next = *stack_b;
	*stack_b = temp;
	copy = *stack_b;
	while (copy->next != temp)
		copy = copy->next;
	copy->next = 0x0;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*copy;
	t_list	*temp_b;
	t_list	*copy_b;

	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	temp = ft_lstlast(*stack_a);
	temp->next = *stack_a;
	*stack_a = temp;
	copy = *stack_a;
	while (copy->next != temp)
		copy = copy->next;
	copy->next = 0x0;
	temp_b = ft_lstlast(*stack_b);
	temp_b->next = *stack_b;
	*stack_b = temp_b;
	copy_b = *stack_b;
	while (copy_b->next != temp_b)
		copy_b = copy_b->next;
	copy_b->next = 0x0;
	write(1, "rrr\n", 4);
}
