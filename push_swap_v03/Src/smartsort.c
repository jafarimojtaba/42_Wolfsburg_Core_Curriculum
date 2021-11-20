/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smartsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:14:51 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/16 21:49:22 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	copy_array_a2(t_list *stack_a, int *m)
{
	int	i;
	int	n;
	int	*sort_array;

	n = ft_lstsize(stack_a);
	sort_array = (int *)ft_calloc(n + 1, sizeof(int));
	i = 0;
	while (i < n)
	{
		sort_array[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	bubblesort(sort_array, n);
	*m = sort_array[n / 2];
	free(sort_array);
}

void	smartsort(t_list **stack_a,t_list **stack_b)
{
	int	size_a;
	int	m;
	int	i;
	size_a = ft_lstsize(*stack_a);
	copy_array_a2(*stack_a, &m);
	i = 0;
	while (i < (size_a / 2))
	{
		if ((*stack_a)->content >= m)
			px("pb", stack_a, stack_b, &i);
		else
			rx("ra", stack_a);
	}
	// if (ft_lstsize(*stack_a) > 10)
	// 	smartsort(stack_a, stack_b);
	// else
	print_stack(*stack_a ,*stack_b);
	sort_a(stack_a, stack_b);
}