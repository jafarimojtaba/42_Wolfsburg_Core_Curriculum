/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:43:23 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/16 18:57:26 by mjafari          ###   ########.fr       */
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
	while ((*n) - 1 >= 0)
	{
		if (org_array[*n - 1] == sort_array[*n - 1])
			(*n)--;
		else
			return (sort_array[(*n) / 2]);
	}
	return (sort_array[0]);
}

void	copy_array_a(t_list *stack_a, int *m, int *chunk)
{
	int	i;
	int	n;
	int	*org_array;
	int	*sort_array;

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
	free(org_array);
	free(sort_array);
}

void	sort_3_a(t_list **stack_a, t_list **stack_b, int m, int size)
{
	int	f;
	int	s;
	int	l;
	int	i;

	i = 0;
	while (i < size && ft_lstsize(*stack_a) > 1 && !a_is_sorted(*stack_a))
	{
		check_same_poss(stack_a, stack_b);
		f = (*stack_a)->content;
		s = (*stack_a)->next->content;
		l = ft_lstlast(*stack_a)->content;
		if (f > l && f > s && f > m)
			rx("ra", stack_a);
		else if (s < f && s < m && s <=l)
			sx("sa", *stack_a);
		else if (l < s && l < f && l < m)
			rrx("rra", stack_a);
		else if (f < s && f <= l && f < m)
			px("pb", stack_a, stack_b, &i);
		else if (f == m && i == size - 1)
			px("pb", stack_a, stack_b, &i);
		else
			rx("ra", stack_a);
	}
}

void	sort_a(t_list **stack_a, t_list **stack_b)
{
	int	chunk[20];
	int	m;
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (!check_the_end(*stack_a, *stack_b, size) && ft_lstsize(*stack_a) > 0)
	{
		copy_array_a(*stack_a, &m, &chunk[i]);
		sort_3_a(stack_a, stack_b, m, chunk[i]);
		if (chunk[i] == 0)
			sort_b(stack_a, stack_b, &chunk[i - 1], i);
		i++;
	}
	i--;
	if (a_is_sorted(*stack_a) && !b_is_sorted(*stack_b))
		sort_b(stack_a, stack_b, &chunk[i], i);
	if (a_is_sorted(*stack_a) && b_is_sorted(*stack_b)
		&& is_b_les_a(*stack_a, *stack_b))
		while (*stack_b)
			px("pa", stack_b, stack_a, &i);
	return ;
}
