/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:24:03 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/08 16:45:33 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

typedef struct s_vars
{
	char	**arr;
	void	*mlx;
	void	*win;
	void	*img;
	int		p_i;
	int		p_j;
	int		img_w;
	int		img_h;
	int		collected;
	int		mc;
	int		pc;
	int		ec;
	int		cc;
}	t_vars;

int		ft_close(void);
void	handle_error(char *msg);
void	check_argv(char *str);
char	**convert_ber_to_arr(char *file, int *row);
void	print_map(char **arr, t_vars *vars, int row, int col);
int		key_hook(int keycode, t_vars *vars);
void	move_up(t_vars *vars, int i, int j);
void	move_down(t_vars *vars, int i, int j);
void	move_right(t_vars *vars, int i, int j);
void	move_left(t_vars *vars, int i, int j);
void	map_pec(t_vars *vars, char **arr, int col, int row);

#endif