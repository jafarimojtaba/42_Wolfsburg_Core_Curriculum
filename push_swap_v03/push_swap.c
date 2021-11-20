/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:51:31 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/16 21:46:52 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3 || !is_valid(argc, argv) || !int_error(argc, argv))
		return (write(2, "Error\n", 6));
	fill_stack(argc, argv, &stack_a);
	if (ft_lstsize(stack_a) < 51)
		sort_a(&stack_a, &stack_b);
	else
		smartsort(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	free_stack(&stack_a, &stack_b);
	return (0);
}
