/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:00:00 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/30 03:48:06 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_b(t_list **stack_a, t_list **stack_b, int chunk[], int i)
{
	while (!b_sorted(*stack_b) && ft_lstsize(*stack_b) > 3 && *chunk > 0)
	{
		make_array_b(*stack_b, *chunk);
		small_sort_b(stack_a, stack_b, chunk, i);
		chunk--;
		i--;
	}
	if (a_sorted(*stack_a) && !b_sorted(*stack_b) && ft_lstsize(*stack_b) == 2)
		sb(*stack_b);
	if (a_sorted(*stack_a) && !b_sorted(*stack_b) && ft_lstsize(*stack_b) == 3)
		sort_3_b(stack_a, stack_b);
	if (a_sorted(*stack_a) && b_sorted(*stack_b) && ft_lstsize(*stack_b) > 0)
		while (*stack_b)
			pa(stack_a, stack_b);
	if (a_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
	{
		ft_free(stack_a, stack_b);
		exit(1);
	}
}

void	small_sort_b(t_list **stack_a, t_list **stack_b, int *size, int ch)
{
	int	r_b;
	int	i;
	int	m;

	m = make_array_b(*stack_b, *size);
	r_b = 0;
	i = 0;
	if (*size <= 3)
		sort_till_2(stack_a, stack_b, size);
	while (*size > 3)
	{
		i = pa_rb(stack_a, stack_b, &r_b, size);
		if (!a_sorted(*stack_a))
			sort_chunk_a(stack_a, stack_b, &i);
		if (r_b > 0 && ch > 0)
			*size = (*size + rrb_pa(stack_a, stack_b, &r_b, m));
		if (*size > 0)
		{
			m = make_array_b(*stack_b, *size);
			small_sort_b(stack_a, stack_b, size, ch);
		}
	}
}

void	sort_chunk_b(t_list **stack_a, t_list **stack_b, int chunk[])
{
	int	m;

	while (!b_sorted(*stack_b) && *chunk > 0)
	{
		make_array_chunk_b(*stack_b, &m, *chunk);
		small_sort_ch_b(stack_a, stack_b, m, chunk);
		chunk--;
	}
}

void	small_sort_ch_b(t_list **stack_a, t_list **stack_b, int m, int *size)
{
	int	r_b;
	int	i;

	r_b = 0;
	i = 0;
	if (*size <= 3)
		sort_till_2(stack_a, stack_b, size);
	while (*size > 3)
	{
		i = pa_rb(stack_a, stack_b, &r_b, size);
		if (i == 2 && !a_sorted(*stack_a))
			sa(*stack_a);
		if (!a_sorted(*stack_a))
			sort_chunk_a(stack_a, stack_b, &i);
		*size = (*size + rrb_pa(stack_a, stack_b, &r_b, m));
		if (*size > 0)
		{
			m = make_array_b(*stack_b, *size);
			small_sort_b(stack_a, stack_b, size, 1);
		}
	}
}

void	sort_till_2(t_list **stack_a, t_list **stack_b, int *size)
{
	if (*size == 1)
	{
		pa(stack_a, stack_b);
		(*size)--;
	}
	if (*size == 2)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			sb(*stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		*size = (*size) - 2;
	}
	if (*size == 3)
	{
		sort_chunk_3_b(stack_a, stack_b);
		*size = (*size) - 3;
	}
}
