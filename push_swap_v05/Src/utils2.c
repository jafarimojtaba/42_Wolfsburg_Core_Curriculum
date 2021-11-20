/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:35:27 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/17 21:32:02 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int *init_sort_a(t_list *stack_a)
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
	return (sort_array);
}

int *init_rev_sort_a(t_list *stack_a)
{
	int	i;
	int	n;
	int	*rev_sort_array;

	n = ft_lstsize(stack_a);
	rev_sort_array = (int *)ft_calloc(n + 1, sizeof(int));
	i = 0;
	while (i < n)
	{
		rev_sort_array[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	bubblesort_rev(rev_sort_array, n);
	return (rev_sort_array);
}

void print_int_array(int *array , int n)
{
	int i = 0;
	while (i < n)
	{
		printf("%d ", array[i]);
		i++;
	}	
}