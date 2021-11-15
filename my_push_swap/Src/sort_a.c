/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:43:23 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/15 22:05:44 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int a_is_sorted(t_list *stack_x)
{
	t_list *temp;
	int i;

	temp = stack_x;
	i = ft_lstsize(stack_x);
	while (i-- > 1)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int check_sort_till_where(int *org_array, int *sort_array, int *n)
{
	while ((*n) - 1 >= 0)
	{
		if (org_array[*n - 1] == sort_array[*n - 1])
			(*n)--;
		else
			return (sort_array[(*n) / 2]);
	}
	return (sort_array[0]);
}

void copy_array_a(t_list *stack_a, int *m, int *chunk)
{
	int i;
	int n;
	int *org_array;
	int *sort_array;

	n = ft_lstsize(stack_a);
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
	// puts("copy_array_a l:64");
	// i = 0;
	// while (i < n)
	// {
	// 	printf("%d ", sort_array[i]);
	// 	i++;
	// }
	// puts("");
	free(org_array);
	free(sort_array);
}

void sort_3_a(t_list **stack_a, t_list **stack_b, int m, int size)
{
	int f;
	int s;
	int l;
	int i;

	i = 0;
	// puts("sort_3_a l:77");
	// printf("m = %d\n", m);
	// printf("size = %d\n", size);
	while (i < size && ft_lstsize(*stack_a) > 1)
	{
		f = (*stack_a)->content;
		s = (*stack_a)->next->content;
		l = ft_lstlast(*stack_a)->content;

		if (f < s && f <= l && f < m)
		{
			px("pb", stack_a, stack_b);
			i++;
		}
		else if (s < f && s <= l && s < m)
		{
			sx("sa", *stack_a);
			px("pb", stack_a, stack_b);
			i++;
		}
		else if (l < s && l < f && l < m)
		{
			rrx("rra", stack_a);
			px("pb", stack_a, stack_b);
			i++;
		}
		else if (f == m && i == size - 1)
		{
			px("pb", stack_a, stack_b);
			i++;
		}
		else
			rx("ra", stack_a);
	}
	// puts("sort_3_a l:108");
	// print_stack(*stack_a, *stack_b);
}

void sort_a(t_list **stack_a, t_list **stack_b)
{
	int chunk[20];
	int m;
	int size;
	size_t i;

	size = ft_lstsize(*stack_a);
	i = 0;
	// puts("sort_a.c l:121");
	while (!check_the_end(*stack_a, *stack_b, size) && ft_lstsize(*stack_a) > 0)
	{
		// puts("sort_a.c l:124");
		copy_array_a(*stack_a, &m, &chunk[i]);
		// puts("sort_a.c l:126");
		sort_3_a(stack_a, stack_b, m, chunk[i]);
		// puts("sort_a.c l:128");
		if (chunk[i] == 0)
		{
			// puts("sort_a.c l:131");
			sort_b(stack_a, stack_b, &chunk[i - 1]);
		}
		i++;
	}
	i--;
	// puts("sort_a.c l:136");
	// puts("sort_a.c l:136");
	if (a_is_sorted(*stack_a) && !b_is_sorted(*stack_b))
	{
		// puts("sort_a.c l:138");
		sort_b(stack_a, stack_b, &chunk[i]);
		// puts("sort_a.c l:140");
	}
	if (a_is_sorted(*stack_a) && b_is_sorted(*stack_b) && is_b_les_a(*stack_a, *stack_b))
	{
		// puts("sort_a.c l:144");
		while (*stack_b)
			px("pa", stack_b, stack_a);
		// puts("sort_a.c l:147");
	}
	return;
}
