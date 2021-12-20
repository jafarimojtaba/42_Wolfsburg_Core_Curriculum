/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:04:02 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/28 19:20:30 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	strsize(char *s)
{
	char	*t;
	int		i;

	t = s;
	i = 0;
	while (*t)
	{
		i++;
		t++;
	}
	return (i);
}

int	run_order(char *order, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(order, "sa", strsize(order)) == 0)
		sa2(*stack_a);
	else if (ft_strncmp(order, "sb", strsize(order)) == 0)
		sb2(*stack_b);
	else if (ft_strncmp(order, "ss", strsize(order)) == 0)
		ss2(*stack_a, *stack_b);
	else if (ft_strncmp(order, "pa", strsize(order)) == 0)
		pa2(stack_a, stack_b);
	else if (ft_strncmp(order, "pb", strsize(order)) == 0)
		pb2(stack_a, stack_b);
	else if (ft_strncmp(order, "rra", strsize(order)) == 0)
		rra2(stack_a);
	else if (ft_strncmp(order, "rrb", strsize(order)) == 0)
		rrb2(stack_b);
	else if (ft_strncmp(order, "rrr", strsize(order)) == 0)
		rrr2(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	run_order2(char *order, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(order, "ra", strsize(order)) == 0)
		ra2(stack_a);
	else if (ft_strncmp(order, "rb", strsize(order)) == 0)
		rb2(stack_b);
	else if (ft_strncmp(order, "rr", strsize(order)) == 0)
		rr2(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	check_order(char *order, t_list **stack_a, t_list **stack_b)
{
	char	*o;
	int		i;

	i = 0;
	o = order;
	while (*order)
	{
		if (*order == '\n')
		{
			*order = '\0';
			o = &order[-i];
			i = 0;
			order++;
			if (!run_order(o, stack_a, stack_b))
				if (!run_order2(o, stack_a, stack_b))
					return (0);
			continue ;
		}
		order++;
		i++;
	}
	return (1);
}

void	checker(t_list **stack_a, t_list **stack_b)
{
	char	*orders;
	char	*gnl;
	int		i;

	i = ft_lstsize(*stack_a);
	orders = ft_calloc(1, sizeof(char));
	gnl = get_next_line(0);
	while (gnl)
	{
		ft_strjoin(&orders, gnl);
		gnl = get_next_line(0);
	}
	if (!check_order(orders, stack_a, stack_b))
		write(2, "Error\n", 6);
	else if (check_end(*stack_a, *stack_b, i))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(orders);
	if (gnl)
		free(gnl);
}
