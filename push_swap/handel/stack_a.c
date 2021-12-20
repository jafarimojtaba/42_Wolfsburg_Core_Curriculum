/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:06:11 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/30 03:48:01 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a(t_list **stack_a, t_list **stack_b)
{
	int		chunk[20];
	int		m;
	int		size_a;
	size_t	i;
	int		new_size;

	size_a = ft_lstsize(*stack_a);
	i = 0;
	while (!check_end(*stack_a, *stack_b, size_a) && ft_lstsize(*stack_a) > 3)
	{
		if (a_sorted(*stack_a) && top_a_les_b(*stack_a, *stack_b))
			break ;
		new_size = ft_lstsize(*stack_a);
		make_array_a(*stack_a, &m, &chunk[i]);
		i++;
		small_sort_a(stack_a, stack_b, m, new_size);
	}
	i--;
	if (!a_sorted(*stack_a) && ft_lstsize(*stack_a) == 2)
		sa(*stack_a);
	if (!a_sorted(*stack_a) && ft_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	sort_b(stack_a, stack_b, &chunk[i], i);
}

void	small_sort_a(t_list **stack_a, t_list **stack_b, int m, int size)
{
	int	f;
	int	l;
	int	i;

	i = 0;
	while (i < size / 2 && ft_lstsize(*stack_a) > 2)
	{
		f = (*stack_a)->content;
		l = ft_lstlast(*stack_a)->content;
		if (f < m)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if (l < m)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	sort_chunk_a(t_list **stack_a, t_list **stack_b, int *pa)
{
	int		chunk[10];
	int		size;
	int		m;
	size_t	i;

	size = *pa;
	i = 0;
	while (!a_sorted(*stack_a) && size > 3)
	{
		make_array_chunk_a(*stack_a, &m, &chunk[i], size);
		i++;
		small_sort_ch_a(stack_a, stack_b, m, &size);
	}
	i--;
	if (!a_sorted(*stack_a) && size == 2)
		sa(*stack_a);
	if (!a_sorted(*stack_a) && (ft_lstsize(*stack_a) == 3 || size == 3))
		sort_chunk_3(stack_a, stack_b);
	sort_chunk_b(stack_a, stack_b, &chunk[i]);
}

void	small_sort_ch_a(t_list **stack_a, t_list **stack_b, int m, int *size)
{
	int	f;
	int	r_a;

	r_a = 0;
	while (cmp_chunk_a_m(*stack_a, *size, m))
	{
		f = (*stack_a)->content;
		if (f < m)
		{
			pb(stack_a, stack_b);
			(*size)--;
		}
		else
		{
			ra(stack_a);
			r_a++;
		}
	}
	while (r_a > 0)
	{
		rra(stack_a);
		r_a--;
	}
}
