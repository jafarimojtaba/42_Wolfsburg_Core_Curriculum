/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:01:42 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/13 18:44:24 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
**push from top of stack first to top of stack second
*/
void	px(char *cmd, t_list **first, t_list **second)
{
	t_list	*temp;

	if (ft_lstsize(*first) == 0)
		return ;
	temp = (*first);
	*first = (*first)->next;
	temp->next = NULL;
	ft_lstadd_front(second, temp);
	if (*cmd != '\0')
	{
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 2);
	}
}

void	sx(char *cmd, t_list *stack_x)
{
	int	temp;

	if (ft_lstsize(stack_x) < 2)
		return ;
	temp = stack_x->next->content;
	stack_x->next->content = stack_x->content;
	stack_x->content = temp;
	if (*cmd != '\0')
	{
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 2);
	}
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b) < 2)
		return ;
	sx("", stack_a);
	sx("", stack_b);
	write(1, "ss\n", 3);
}
