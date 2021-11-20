/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:16:16 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/17 08:27:34 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	b_is_sorted(t_list *stack_x)
{
	t_list	*temp;
	int		i;

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

void	copy_array_b(t_list *stack_b, int *m, int *chunk)
{
	int	i;
	int	*array;

	i = 0;
	array = (int *)ft_calloc(*chunk + 1, sizeof(int));
	while (i < *chunk && stack_b)
	{
		array[i] = stack_b->content;
		stack_b = stack_b->next;
		i++;
	}
	bubblesort(array, i);
	*m = array[i / 2];
	*chunk = i;
	free(array);
}

int	check_4_b(t_list **stack_b, int m, int *rb)
{
	int	f;
	int	s;
	int th;
	int	l;

	f = (*stack_b)->content;
	s = (*stack_b)->next->content;
	th = (*stack_b)->next->next->content;
	l = ft_lstlast(*stack_b)->content;

	if (s > m && s > f && s > th && s > l)
		sx("sb", *stack_b);
	else if (l > m && l > f && l > s && l >= th)
		{
			rrx("rrb", stack_b);
			rb--;
		}
	else if (th > m && th > f && th > s && th >= l)
	{
		rx("rb", stack_b);
		rb++;
		sx("sb", *stack_b);
	}
	if (b_is_sorted(*stack_b))
		return (1);
	return (0);
}

void	sort_3_b(t_list **stack_a, t_list **stack_b, int m, int size, int ch)
{
	int	f;
	int	s;
	int	l;
	int	i;
	int	rb;
	int th;

	i = 0;
	rb = 0;
	

	while (i < size / 2 - 1)
	{
		// if (ft_lstsize(*stack_a) > 2)
		// 	 check_4_b(stack_b, m, &rb);
		// f = (*stack_b)->content;
	f = (*stack_b)->content;
	s = (*stack_b)->next->content;
	th = (*stack_b)->next->next->content;
	l = ft_lstlast(*stack_b)->content;

	if (s > m && s > f && s > l && s > th)
		sx("sb", *stack_b);
	else if (l > m && l > f && l > s && l >= th)
		{
			rrx("rrb1", stack_b);
			rb--;
		}
	else if (th > m && th > f && th > s && th > l)
	{
		rx("rb1", stack_b);
		rb++;
		sx("sb", *stack_b);
	}
	else if (f >= m && f > l && f > s && f > th)
			px("pa", stack_b, stack_a, &i);
		// if (f >= m)
		// 	px("pa", stack_b, stack_a, &i);
		else
			{
				rx("rb2", stack_b);
				rb++;
			}
		// f = (*stack_b)->content;
		// s = (*stack_b)->next->content;
		// l = ft_lstlast(*stack_b)->content;
		// if ( s > f && s > l && s >m)
		// 	sx("sb", *stack_b);
		// else if (l > f && l > s && l > m)
		// 	{
		// 		rrx("rrb", stack_b);
		// 		rb--;
		// 	}
		// else if (f >= m && f > l && f > s)
		// 	px("pa", stack_b, stack_a, &i);
		// else if (f < m)
		// 	{
		// 		rx("rb", stack_b);
		// 		rb++;
		// 	}

	}
	// while (rb > 0 && ch > 2 )
	// 		{
	// 			rrx("rrb", stack_b);
	// 			rb--;
	// 			if ((*stack_b)->content == m)
	// 				px("pa", stack_b, stack_a, &i);
	// 		}	
	// i = 0;
	// // print_stack(*stack_a, *stack_b);

	// while (size != size / 2 + i && *stack_b)
	// {
	// 		px("pa1", stack_b, stack_a, &i);
	// }
		while (rb > 0 && ch > 2)
	{
		rrx("rrb", stack_b);
		rb--;
	}
	i = 0;
	while (size != size / 2 + i && *stack_b)
		px("pa", stack_b, stack_a, &i);
	if (a_is_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
		return ;
}

void	sort_b(t_list **stack_a, t_list **stack_b, int chunk[], int i)
{
	int	m;

	// puts("sort_B");
	while (*stack_b && *chunk > 0)
	{
		copy_array_b(*stack_b, &m, &chunk[0]);
		sort_3_b(stack_a, stack_b, m, *chunk, i);
		if (a_is_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
			exit (1) ;
		// printf("chunk =%d", chunk[0]);
		chunk--;
	}
	if (!a_is_sorted(*stack_a) && b_is_sorted(*stack_b))
		sort_a(stack_a, stack_b);
}
