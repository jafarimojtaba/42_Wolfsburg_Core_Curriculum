/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:06:19 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/15 23:48:46 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "./Libft/libft.h"

/*utils.c */
void	fill_stack(int argc, char *argv[], t_list **stack_a);
void	print_stack(t_list *stack_a, t_list *stack_b);
void	free_stack(t_list **stack_a, t_list **stack_b);
void	check_same_poss(t_list **stack_a, t_list **stack_b);

/*error_handeler.c*/
int		is_valid(int argc, char *argv[]);
int		int_error(int argc, char *argv[]);
int		numcmp(char *s1, char *s2);

/*sort_a.c*/
int		a_is_sorted(t_list *stack_x);
void	sort_a(t_list **stack_a, t_list **stack_b);

/*sort_b.c*/
int		b_is_sorted(t_list *stack_x);
void	sort_b(t_list **stack_a, t_list **stack_b, int chunk[]);

/*sort_utils.c*/
int		is_b_les_a(t_list *stack_a, t_list *stack_b);
int		check_the_end(t_list *stack_a, t_list *stack_b, int i);
void	swap(int *a, int *b);
void	bubblesort(int array[], int n);

/*ps_commands.c*/
void	px(char *cmd, t_list **first, t_list **second, int *i);
void	sx(char *cmd, t_list *stack_x);
void	ss(t_list *stack_a, t_list *stack_b);

/*r_commands.c*/
void	rx(char *cmd, t_list **stack_x);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrx(char *cmd, t_list **stack_x);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif