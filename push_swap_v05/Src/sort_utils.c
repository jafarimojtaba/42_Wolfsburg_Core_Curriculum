/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:01:28 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/17 20:45:46 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_b_les_a(t_list *stack_a, t_list *stack_b)
{
	while (stack_b)
	{
		if (stack_a->content < stack_b->content)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int	check_the_end(t_list *stack_a, t_list *stack_b, int i)
{
	if (ft_lstsize(stack_a) == i)
		if (ft_lstsize(stack_b) == 0)
			if (a_is_sorted(stack_a) == 1)
				return (1);
	return (0);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubblesort(int array[], int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (array[i] > array[j])
				swap(&array[i], &array[j]);
			j++;
		}
		i++;
	}
}

void	bubblesort_rev(int array[], int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (array[i] < array[j])
				swap(&array[i], &array[j]);
			j++;
		}
		i++;
	}
}
