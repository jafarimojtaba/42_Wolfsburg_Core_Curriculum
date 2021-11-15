/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:16:16 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/15 22:40:33 by mjafari          ###   ########.fr       */
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

void	sort_3_b(t_list **stack_a, t_list **stack_b, int m, int size, int ch)
{
	int	f;
	int	i;
	int	rb;

	i = 0;
	rb = 0;
	while (i < size / 2)
	{
		f = (*stack_b)->content;
		if (f < m)
		{
			rx("rb", stack_b);
			rb++;
		}
		else
		{
			px("pa", stack_b, stack_a);
			i++;
		}
	}
	while (rb > 0 && ch > 0)
	{
		rrx("rrb", stack_b);
		rb--;
	}
	i = 0;
	while (size != size / 2 + i && *stack_b)
	{
		px("pa", stack_b, stack_a);
		i++;
	}
	if(a_is_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
			return;
}

void	sort_b(t_list **stack_a, t_list **stack_b, int chunk[], int i)
{
	int	m;
	while (*stack_b && *chunk > 0)
	{
		copy_array_b(*stack_b, &m, &chunk[0]);
		sort_3_b(stack_a, stack_b, m, *chunk, i);
		chunk--;
	}
	if (!a_is_sorted(*stack_a) && b_is_sorted(*stack_b))
		// {puts("srt_b.c l:100");
		sort_a(stack_a, stack_b);
		// puts("srt_b.c l:102");}
}
