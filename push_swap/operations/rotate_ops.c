/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:09:41 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/26 23:46:19 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	last = ft_lstlast(*stack_a);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next = temp;
	temp->next = 0x0;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	last = ft_lstlast(*stack_b);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	last->next = temp;
	temp->next = 0x0;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;
	t_list	*temp_b;
	t_list	*last_b;

	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	last = ft_lstlast(*stack_a);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next = temp;
	temp->next = 0x0;
	last_b = ft_lstlast(*stack_b);
	temp_b = *stack_b;
	*stack_b = (*stack_b)->next;
	last_b->next = temp_b;
	temp_b->next = 0x0;
	write(1, "rr\n", 3);
}
