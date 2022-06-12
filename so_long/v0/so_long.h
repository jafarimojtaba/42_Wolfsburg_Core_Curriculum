/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:29:04 by mjafari           #+#    #+#             */
/*   Updated: 2022/02/24 11:39:46 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

typedef struct s_vars
{
	void *mlx;
	void *win;
	void *img;
} t_vars;

typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}				t_param;

void handle_error(char *msg);

#endif