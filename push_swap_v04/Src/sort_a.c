/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:43:23 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/19 23:35:21 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int a_is_sorted(t_list *stack_x)
{
	t_list *temp;
	int i;

	temp = stack_x;
	i = ft_lstsize(stack_x);
	while (i > 1)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
		i--;
	}
	return (1);
}

int check_sort_till_where(int *org_array, int *sort_array, int *n)
{
	while ((*n) > 0)
	{
		if (org_array[*n - 1] == sort_array[*n - 1])
			(*n)--;
		else
			return (sort_array[(*n) / 2]);
	}
	return (sort_array[0]);
}

int copy_array_a(t_list *stack_a, int *m, int *chunk, int n)
{
	int i;
	int *org_array;
	int *sort_array;

	org_array = (int *)ft_calloc(n + 1, sizeof(int));
	sort_array = (int *)ft_calloc(n + 1, sizeof(int));
	i = 0;
	while (i < n)
	{
		org_array[i] = stack_a->content;
		sort_array[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	bubblesort(sort_array, n);
	*m = check_sort_till_where(org_array, sort_array, &n);
	*chunk = n / 2;
	free(org_array);
	free(sort_array);
	// printf("mid = %d, sort_a.c l:51\n", *m);
	// printf("chunk = %d, sort_a.c l:52\n", chunk[0]);
	return (n);
}

int check_4_a(t_list **stack_a, int m)
{
	int f;
	int s;
	int th;
	int l;

	f = (*stack_a)->content;
	s = (*stack_a)->next->content;
	th = (*stack_a)->next->next->content;
	l = ft_lstlast(*stack_a)->content;

	if (s < m && s < f && s <= th && s <= l)
		sx("sa", *stack_a);
	else if (l < m && l < f && l <= s && l <= th)
		rrx("rra", stack_a);
	else if (th < m && th < f && th <= s && th <= l)
	{
		rx("ra", stack_a);
		sx("sa", *stack_a);
	}
	if (a_is_sorted(*stack_a))
		return (1);
	return (0);
}

void sort_3_a(t_list **stack_a, t_list **stack_b, int m, int *chunk)
{
	int f;
	int i;

	i = 0;
	while (i < *chunk && ft_lstsize(*stack_a) > 2)
	{
		if (ft_lstsize(*stack_a) > 2 && check_4_a(stack_a, m))
		{
			*chunk = *chunk - i;
			break;
		}
		f = (*stack_a)->content;
		if (f < m)
			px("pb", stack_a, stack_b, &i);
		else
			rx("ra", stack_a);
	}
	print_stack(*stack_a, *stack_b);
}

void sort_a(t_list **stack_a, t_list **stack_b, int size)
{
	int chunk[20];
	int m;
	int org_size;
	int i;

	puts("sorta.c");
	org_size = ft_lstsize(*stack_a);
	ft_bzero(chunk, 20);
	i = 0;
	while (!check_the_end(*stack_a, *stack_b, org_size) && size > 0 && ft_lstsize(*stack_a) > 2 && a_is_sorted(*stack_a) == 0)
	{
		copy_array_a(*stack_a, &m, &chunk[i], size);
		printf("chunk in sorta.c = %d\n", chunk[i]);
		size = size - chunk[i];
		sort_3_a(stack_a, stack_b, m, &chunk[i]);
		if (chunk[i] < 2 && chunk[i] > 0 && a_is_sorted(*stack_a))
			sort_b(stack_a, stack_b, &chunk[i - 1], i - 1);
		i++;
	}
	i--;
	if (!a_is_sorted(*stack_a) && ft_lstsize(*stack_a) == 2)
		sx("sa", *stack_a);

	if (a_is_sorted(*stack_a) && !b_is_sorted(*stack_b))
		sort_b(stack_a, stack_b, &chunk[i], i);
	// print_stack(*stack_a, *stack_b);	
	
	// if (a_is_sorted(*stack_a) && b_is_sorted(*stack_b) && is_b_les_a(*stack_a, *stack_b))
	// 	while (*stack_b)
	// 		px("pa", stack_b, stack_a, &i);
	return;
}


