/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:10:02 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/27 03:18:14 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble_sort(int array[], int n)
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

void	make_array_a(t_list *stack_a, int *m, int *chunk)
{
	int	i;
	int	n;
	int	*array;

	i = 0;
	n = ft_lstsize(stack_a);
	array = (int *)ft_calloc(n + 1, sizeof(int));
	while (i < n)
	{
		array[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	bubble_sort(array, n);
	*m = array[n / 2];
	*chunk = n / 2;
	free(array);
}

void	make_array_chunk_a(t_list *stack_a, int *m, int *chunk, int size)
{
	int	i;
	int	n;
	int	*array;

	i = 0;
	n = size;
	array = (int *)ft_calloc(n + 1, sizeof(int));
	while (i < n)
	{
		array[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	bubble_sort(array, n);
	*m = array[n / 2];
	*chunk = n / 2;
	free(array);
}

int	make_array_b(t_list *stack_b, int chunk)
{
	int	i;
	int	m;
	int	*array;

	i = 0;
	array = (int *)ft_calloc(chunk + 1, sizeof(int));
	while (i < chunk)
	{
		array[i] = stack_b->content;
		stack_b = stack_b->next;
		i++;
	}
	bubble_sort(array, chunk);
	m = array[chunk / 2];
	free(array);
	return (m);
}

void	make_array_chunk_b(t_list *stack_b, int *m, int chunk)
{
	int	i;
	int	*array;

	i = 0;
	array = (int *)ft_calloc(chunk + 1, sizeof(int));
	while (i < chunk)
	{
		array[i] = stack_b->content;
		stack_b = stack_b->next;
		i++;
	}
	bubble_sort(array, chunk);
	*m = array[chunk / 2];
	free(array);
}
