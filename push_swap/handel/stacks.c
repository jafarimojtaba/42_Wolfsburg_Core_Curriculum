/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:02:23 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/28 04:59:03 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stack(int argc, char *argv[], t_list **stack_a)
{
	int	i;

	*stack_a = ft_lstnew(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	ft_free(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (stack_a)
	{
		while (*stack_a)
		{
			temp = *stack_a;
			*stack_a = (*stack_a)->next;
			free(temp);
		}
	}
	if (stack_b)
	{
		while (*stack_b)
		{
			temp = *stack_b;
			*stack_b = (*stack_b)->next;
			free(temp);
		}
	}
}

int	pa_rb(t_list **stack_a, t_list **stack_b, int *r_b, int *size)
{
	int	f;
	int	i;
	int	m;

	i = 0;
	m = make_array_b(*stack_b, *size);
	{
		while (cmp_chunk_b_m(*stack_b, *size, m) && *size > 2)
		{
			f = (*stack_b)->content;
			if (f > m)
			{
				pa(stack_a, stack_b);
				(*size)--;
				i++;
			}
			else if (*r_b < *size)
			{
				rb(stack_b);
				(*r_b)++;
			}
		}
		return (i);
	}
	return (0);
}

int	rrb_pa(t_list **stack_a, t_list **stack_b, int *r_b, int m)
{
	int	f;
	int	size;

	size = 0;
	if (*r_b > 0)
	{
		while (*r_b > 0)
		{
			rrb(stack_b);
			f = (*stack_b)->content;
			if (f == m)
			{
				pa(stack_a, stack_b);
				size--;
			}
			(*r_b)--;
		}
		return (size);
	}
	return (0);
}
