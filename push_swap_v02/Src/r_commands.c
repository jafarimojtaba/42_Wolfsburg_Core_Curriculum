/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:10:14 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/16 00:07:27 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
**ra :rotate a- shift up all elements of stackaby 1.
**The first element becomes the last one
*/
void	rx(char *cmd, t_list **stack_x)
{
	t_list	*temp;

	if (ft_lstsize(*stack_x) < 2)
		return ;
	temp = *stack_x;
	ft_lstadd_back(stack_x, temp);
	*stack_x = (*stack_x)->next;
	temp->next = NULL;
	if (*cmd != '\0')
	{
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	rx("", stack_a);
	rx("", stack_b);
	write(1, "rr\n", 3);
}

/*
**rra :reverse rotate a- shift down all elements of stackaby 1.
**The last element becomes the first one.
*/
void	rrx(char *cmd, t_list **stack_x)
{
	t_list	*temp;
	int		i;

	if (ft_lstsize(*stack_x) < 2)
		return ;
	i = ft_lstsize(*stack_x);
	temp = ft_lstlast(*stack_x);
	ft_lstadd_front(stack_x, temp);
	while (i-- > 1)
		temp = temp->next;
	temp->next = NULL;
	if (*cmd != '\0')
	{
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	rrx("", stack_a);
	rrx("", stack_b);
	write(1, "rrr\n", 4);
}
