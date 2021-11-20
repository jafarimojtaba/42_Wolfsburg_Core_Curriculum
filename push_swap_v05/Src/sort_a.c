/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:43:23 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/17 22:37:42 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	a_is_sorted(t_list *stack_x)
{
	t_list	*temp;
	int		i;

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

int	check_sort_till_where(int *org_array, int *sort_array, int *n)
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

int	copy_array_a(t_list *stack_a, int *m, int *chunk, int *sorted_org)
{
	int	i;
	int	n;
	int	*new_array;

	n = ft_lstsize(stack_a);
	new_array = (int *)ft_calloc(n + 1, sizeof(int));
	i = 0;
	while (i < n)
	{
		new_array[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	*m = check_sort_till_where(new_array, sorted_org, &n);
	*chunk = n / 2;
	printf("middle = %d\n", *m);
	printf("chunk  = %d\n", *chunk);
	print_int_array(sorted_org, n);
	puts("");
	print_int_array(new_array, i);
	puts("");
	free(new_array);
	return (n);
}

int	check_4_a(t_list **stack_a, int m)
{
	int	f;
	int	s;
	int th;
	int	l;

	f = (*stack_a)->content;
	s = (*stack_a)->next->content;
	th = (*stack_a)->next->next->content;
	l = ft_lstlast(*stack_a)->content;

	if (s < m && s < f && s < th && s < l)
		sx("sa", *stack_a);
	else if (l < m && l < f && l < s && l < th)
		rrx("rra", stack_a);
	else if (th < m && th < f && th < s && th <= l)
	{
		rx("ra", stack_a);
		sx("sa", *stack_a);
	}
	if (a_is_sorted(*stack_a))
		return (1);
	return (0);
}

void	sort_3_a(t_list **stack_a, t_list **stack_b, int m, int chunk)
{
	int	f;
	int	i;

	i = 0;
	printf("chunk = %d\n", chunk);
	printf("m = %d\n", m);
	while (i < chunk && ft_lstsize(*stack_a) > 2 && !a_is_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) > 2 && check_4_a(stack_a, m))
			break ;
		f = (*stack_a)->content;
		if (f < m)
			px("pb", stack_a, stack_b, &i);
		else
			rx("ra", stack_a);
		print_stack(*stack_a, *stack_b);
	}
}

void	sort_a(t_list **stack_a, t_list **stack_b, int *sorted_org, int *rev_sorted_org)
{
	int	chunk[20];
	int	m;
	int	org_size;
	int	i;

	// puts("sorta");
	org_size = ft_lstsize(*stack_a);
	i = 0;
	while (!check_the_end(*stack_a, *stack_b, org_size) && ft_lstsize(*stack_a) > 0 && i < 2)
	{
		copy_array_a(*stack_a, &m, &chunk[i], sorted_org); 
		puts("sort_a l:126");
		if (i == 1)
		 exit(1);
		sort_3_a(stack_a, stack_b, m, chunk[i]);
		puts("sort_a l:128");
		// if (chunk[i] == 1)
		// 	sort_b(stack_a, stack_b, &chunk[i - 1], i, sorted_org, rev_sorted_org);
		// if (a_is_sorted(*stack_a) && b_is_sorted(*stack_b)
		// && is_b_les_a(*stack_a, *stack_b))
		// while (*stack_b)
		// 	px("pa", stack_b, stack_a, &i);
			// exit (1);
		i++;
	}
	i--;
	if (a_is_sorted(*stack_a) && !b_is_sorted(*stack_b))
		sort_b(stack_a, stack_b, &chunk[i], i, sorted_org, rev_sorted_org);
	if (a_is_sorted(*stack_a) && b_is_sorted(*stack_b)
		&& is_b_les_a(*stack_a, *stack_b))
		while (*stack_b)
			px("pa", stack_b, stack_a, &i);
	return ;
}
