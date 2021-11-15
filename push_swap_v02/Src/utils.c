/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:48:44 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/15 23:47:24 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stack(int argc, char *argv[], t_list **stack_a)
{
	int	i;

	*stack_a = ft_lstnew(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	print_stack(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstsize(stack_b) > ft_lstsize(stack_a))
		while (ft_lstsize(stack_b) > ft_lstsize(stack_a))
		{
			printf("\n");
			printf("%c", ' ');
			printf("\t\t");
			printf("%d", stack_b->content);
			stack_b = stack_b->next;
		}
	if (ft_lstsize(stack_a) > ft_lstsize(stack_b))
		while (ft_lstsize(stack_a) > ft_lstsize(stack_b))
		{
			printf("\n");
			printf("%d", stack_a->content);
			stack_a = stack_a->next;
		}
	if (ft_lstsize(stack_a) == ft_lstsize(stack_b))
		while (stack_a)
		{
			printf("\n");
			printf("%d", stack_a->content);
			printf("\t\t");
			printf("%d", stack_b->content);
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
	puts("\n_______		_______");
	puts("stack a		stack b");
}

void	free_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (stack_a)
	{		
		while (*stack_a)
		{
			temp = *stack_a;
			*stack_a = (*stack_a)->next;
			free(temp);
		}
	}
	if (stack_b)
	{
		while (*stack_b)
		{
			temp = *stack_b;
			*stack_b = (*stack_b)->next;
			free(temp);
		}
	}
}

void	check_same_poss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_b)->content < (*stack_b)->next->content)
		ss(*stack_a, *stack_b);
	if ((*stack_a)->content > ft_lstlast(*stack_a)->content
		&& (*stack_b)->content < ft_lstlast(*stack_b)->content)
		rr(stack_a, stack_b);
}
