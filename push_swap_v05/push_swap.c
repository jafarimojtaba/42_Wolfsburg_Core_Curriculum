/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:51:31 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/17 22:50:21 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*sorted_org_a;
	int		*rev_sorted_org_a;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3 || !is_valid(argc, argv) || !int_error(argc, argv))
		return (write(2, "Error\n", 6));
	fill_stack(argc, argv, &stack_a);
	sorted_org_a = init_sort_a(stack_a);
	rev_sorted_org_a = init_rev_sort_a(stack_a);
	print_int_array(sorted_org_a, ft_lstsize(stack_a));
	puts("");
	printf("size = %ld\n", sizeof(sorted_org_a));
	print_int_array(rev_sorted_org_a, ft_lstsize(stack_a));
	
	// sort_a(&stack_a, &stack_b, sorted_org_a, rev_sorted_org_a);
	print_stack(stack_a, stack_b);
	// free_stack(&stack_a, &stack_b);
	return (0);
}
