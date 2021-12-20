/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:13:39 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/28 04:03:18 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cmp_chunk_a_m(t_list *stack_a, int size, int m)
{
	while (size)
	{
		if (stack_a->content < m)
			return (1);
		stack_a = stack_a->next;
		size--;
	}
	return (0);
}

int	cmp_chunk_b_m(t_list *stack_b, int size, int m)
{
	while (size)
	{
		if (stack_b->content > m)
			return (1);
		stack_b = stack_b->next;
		size--;
	}
	return (0);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
