/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:24:03 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/06 17:54:01 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

typedef struct s_vars
{
	char    **arr;
	void	*mlx;
	void	*win;
	void	*img;
	int		p_i;
	int		p_j;
	int 	img_w;
	int		img_h;
	int		collected;
	int		mc;
} t_vars;

void check_argv(char *str);
char **convert_ber_to_arr(char *file);
void print_map(char **arr, t_vars *vars, int row, int col);
void move_up(t_vars *vars, int i, int j, int *mc);
void move_down(t_vars *vars, int i, int j, int *mc);
void move_right(t_vars *vars, int i, int j, int *mc);
void move_left(t_vars *vars, int i, int j, int *mc);

#endif