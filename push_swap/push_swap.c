/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:51:31 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/15 22:38:10 by mjafari          ###   ########.fr       */
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
	// puts("start, push_swap.c l:24");
	fill_stack(argc, argv, &stack_a);
	sort_a(&stack_a, &stack_b);
	// px("pa11", &stack_b, &stack_a);
	// px("pa11", &stack_b, &stack_a);
	// px("pa11", &stack_b, &stack_a);
	// px("pa11", &stack_b, &stack_a);
	// px("pa11", &stack_b, &stack_a);
	// px("pa11", &stack_b, &stack_a);
	// px("pa11", &stack_b, &stack_a);
	// px("pa11", &stack_b, &stack_a);
	// px("pa11", &stack_b, &stack_a);
	// px("pa11", &stack_b, &stack_a);


	print_stack(stack_a, stack_b);
	free_stack(&stack_a, &stack_b);
	return (0);
}
