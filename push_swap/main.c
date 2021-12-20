/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:30:28 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/28 02:38:03 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!is_valid(argc, argv) || !atoi_error(argc, argv))
		return (write(2, "Error\n", 6));
	if (argc < 3)
		return (0);
	fill_stack(argc, argv, &stack_a);
	if (ft_strncmp(argv[0], "./checker", 9) == 0)
		checker(&stack_a, &stack_b);
	else if (argc == 4)
		sort_3(&stack_a);
	else
		sort_a(&stack_a, &stack_b);
	ft_free(&stack_a, &stack_b);
	return (0);
}
