/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:16:16 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/19 23:28:24 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int b_is_sorted(t_list *stack_x)
{
	t_list *temp;
	int i;

	temp = stack_x;
	i = ft_lstsize(stack_x);
	while (i-- > 1)
	{
		if (temp->content > temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void copy_array_b(t_list *stack_b, int *m, int *chunk)
{
	int i;
	int *array;

	i = 0;
	// puts("sort_b.c l:42 copy");
	// printf("chunk2 in copy array1st = %d\n", chunk[0]);

	array = (int *)ft_calloc(*chunk + 1, sizeof(int));
	while (i < *chunk && stack_b)
	{
		array[i] = stack_b->content;
		stack_b = stack_b->next;
		i++;
	}
	// print_int_array(array, i);
	bubblesort_rev(array, i);
	// print_int_array(array, i);
	*m = array[i / 2];
	*chunk = i;
	// printf("chunk2 in copy array = %d\n", chunk[0]);

	free(array);
}
/* note:------------ for every rb in stack b rb counter musbe incremented-----------*/
// int check_4_b(t_list **stack_a, int m)
// {
// 	int f;
// 	int s;
// 	int th;
// 	int l;

// 	f = (*stack_a)->content;
// 	s = (*stack_a)->next->content;
// 	th = (*stack_a)->next->next->content;
// 	l = ft_lstlast(*stack_a)->content;

// 	if (s > m && s > f && s > th && s > l)
// 		sx("sb", *stack_a);
// 	else if (l > m && l > f && l > s && l >= th)
// 		rrx("rrb", stack_a);
// 	else if (th > m && th > f && th > s && th >= l)
// 	{
// 		rx("rb", stack_a);
// 		sx("sb", *stack_a);
// 	}
// 	if (b_is_sorted(*stack_a))
// 		return (1);

// 	return (0);
// }

void sort_3_b(t_list **stack_a, t_list **stack_b, int m, int chunk, int ch)
{
	int f;
	int s;
	int l;
	int i;
	int rb;

	i = 0;
	rb = 0;
	while (i < chunk / 2)
	{
		if (ft_lstsize(*stack_b) > 2 && check_4_b(stack_b, m))
			break;
		f = (*stack_b)->content;
		if (f > m)
			px("pa", stack_b, stack_a, &i);
		else
		{
			rx("rb", stack_b);
			rb++;
		}
		// printf("srt_3_b l:84 mid = %d\n",m);
		// printf("srt_3_b l:87 chunk = %d\n",chunk);
	}
	// print_stack(*stack_a, *stack_b);
	while (rb > 0 && ch > 0)
	{
		rrx("rrb", stack_b);
		rb--;
	}
	i = 0;
	// puts("sort3b nime dowome chunk");
	while (chunk != (chunk / 2) + i && *stack_b)
		px("pa", stack_b, stack_a, &i);
	// if (b_is_sorted(*stack_b)
	// 	&& is_b_les_a(*stack_a, *stack_b))
	// 	while (*stack_b && a_is_sorted(*stack_a))
	// 	{	px("pa", stack_b, stack_a, &i);
	// 	}
	// print_stack(*stack_a, *stack_b);
}

void sort_b(t_list **stack_a, t_list **stack_b, int *chunk, int i)
{
	int m;
	int size_a;
	int d = 0;

	puts("sort_b.c------------------------");
	// printf("chunk2 = %d\t", chunk[0]);
	// printf("m2 = %d\t", m);
	size_a = ft_lstsize(*stack_a);
	puts("01");
	while (*chunk > 0)
	{
		puts("02");

		// puts("sort_b.c l:114 befor copy array");
		printf("chunk2 = %d\n", chunk[0]);
		copy_array_b(*stack_b, &m, &chunk[0]);
		puts("03");

		// puts("sort_b.c l:116 after copy array");

		// printf("chunk2 = %d\t", chunk[0]);
		// printf("m2 = %d\t", m);

		// printf("i = %d\n", i);
		// print_stack(*stack_a, *stack_b);

		while (ft_lstsize(*stack_a) < size_a + chunk[0])
		{
			// printf("size a before change = %d\n", (ft_lstsize(*stack_a)));
			sort_3_b(stack_a, stack_b, m, *chunk, i);
			// printf("size a after change = %d\n", (ft_lstsize(*stack_a)));
			print_stack(*stack_a, *stack_b);
			// printf("size a should become = %d\n", (size_a + chunk[0]));
			if (!a_is_sorted(*stack_a))
				sort_a(stack_a, stack_b, *chunk);
			// puts("sortb l:118");
		}
		// puts("sortb l:122");
		chunk--;
		puts("04");

		// printf("chunk2 after -- = %d\n", chunk[0]);

		// i--;
	}
	// if (!a_is_sorted(*stack_a) && b_is_sorted(*stack_b))
	// 	sort_a(stack_a, stack_b);
}
