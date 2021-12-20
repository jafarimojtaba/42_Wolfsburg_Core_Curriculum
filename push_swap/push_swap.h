/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:12:42 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/30 00:02:47 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define FD_SIZE 4096
# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

/*error*/
int		is_valid(int argc, char *argv[]);
int		numcmp(char *s1, char *s2);
int		atoi_error(int argc, char *argv[]);

/*swap_push*/
void	sa2(t_list *stack_a);
void	sb2(t_list *stack_b);
void	ss2(t_list *stack_a, t_list *stack_b);
void	pa2(t_list **stack_a, t_list **stack_b);
void	pb2(t_list **stack_a, t_list **stack_b);

/*rotate*/
void	ra2(t_list **stack_a);
void	rb2(t_list **stack_b);
void	rr2(t_list **stack_a, t_list **stack_b);

/*rev_rotate*/
void	rra2(t_list **stack_a);
void	rrb2(t_list **stack_b);
void	rrr2(t_list **stack_a, t_list **stack_b);

/*swap_push*/
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

/*rotate*/
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

/*rev_rotate*/
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/*array*/
void	bubble_sort(int array[], int n);
void	make_array_a(t_list *stack_a, int *m, int *chunk);
void	make_array_chunk_a(t_list *stack_a, int *m, int *chunk, int size);
int		make_array_b(t_list *stack_b, int chunk);
void	make_array_chunk_b(t_list *stack_b, int *m, int chunk);

/*check*/
int		a_sorted(t_list *stack_x);
int		b_sorted(t_list *stack_x);
int		check_end(t_list *stack_a, t_list *stack_b, int i);
int		top_a_les_b(t_list *stack_a, t_list *stack_b);

/*stacks*/
void	fill_stack(int argc, char *argv[], t_list **stack_a);
void	ft_free(t_list **stack_a, t_list **stack_b);
int		pa_rb(t_list **stack_a, t_list **stack_b, int *r_b, int *size);
int		rrb_pa(t_list **stack_a, t_list **stack_b, int *r_b, int m);

/*stack_a*/
void	sort_a(t_list **stack_a, t_list **stack_b);
void	small_sort_a(t_list **stack_a, t_list **stack_b, int m, int size);
void	sort_chunk_a(t_list **stack_a, t_list **stack_b, int *rb);
void	small_sort_ch_a(t_list **stack_a, t_list **stack_b, int m, int *size);

/*stack_b*/
void	sort_b(t_list **stack_a, t_list **stack_b, int chunk[], int ch);
void	small_sort_b(t_list **stack_a, t_list **stack_b, int *size, int ch);
void	sort_chunk_b(t_list **stack_a, t_list **stack_b, int chunk[]);
void	small_sort_ch_b(t_list **stack_a, t_list **stack_b, int m, int *size);
void	sort_till_2(t_list **stack_a, t_list **stack_b, int *size);

/*utils*/
void	ft_print_stack(t_list *stack_a, t_list *stack_b);
int		cmp_chunk_a_m(t_list *stack_a, int size, int m);
int		cmp_chunk_b_m(t_list *stack_b, int size, int m);
void	swap(int *a, int *b);

/*get_next_line*/
char	*get_next_line(int fd);

/*checker*/
void	checker(t_list **stack_a, t_list **stack_b);

/*sort_3*/
void	sort_3(t_list **stack_a);
void	sort_chunk_3(t_list **stack_a, t_list **stack_b);
void	sort_chunk_32(t_list **stack_a, t_list **stack_b);
void	sort_chunk_33(t_list **stack_a, t_list **stack_b);

/*sort_chunk_3_b*/
void	sort_chunk_3_b(t_list **stack_a, t_list **stack_b);
void	sort_chunk_3_b2(t_list **stack_a, t_list **stack_b);
void	sort_chunk_3_b3(t_list **stack_a, t_list **stack_b);
void	sort_chunk_3_b4(t_list **stack_a, t_list **stack_b);
void	sort_chunk_3_b5(t_list **stack_a, t_list **stack_b);

/*sort_3_b*/
void	sort_3_b(t_list **stack_a, t_list **stack_b);
void	sort_3_b2(t_list **stack_a, t_list **stack_b);

#endif