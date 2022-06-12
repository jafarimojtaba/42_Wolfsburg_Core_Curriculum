/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:32:46 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/08 11:55:52 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_control(t_vars *vars, char **arr, int *i, int *j)
{
	if (arr[*i][*j] == '1')
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/wall.xpm",
				&vars->img_w, &vars->img_h);
	else if (arr[*i][*j] == '0')
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm",
				&vars->img_w, &vars->img_h);
	else if (arr[*i][*j] == 'P')
	{
		vars->p_i = *i;
		vars->p_j = *j;
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./imgs/player.xpm", &vars->img_w, &vars->img_h);
	}
	else if (arr[*i][*j] == 'E')
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./imgs/helicopter.xpm", &vars->img_w, &vars->img_h);
	else if (arr[*i][*j] == 'C')
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/gas.xpm",
				&vars->img_w, &vars->img_h);
	else
		return (1);
	return (0);
}

void	put_img(t_vars *vars, int col, int row)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm",
			&vars->img_w, &vars->img_h);
	vars->win = mlx_new_window(vars->mlx, col * 40, row * 40, "So Long");
}

void	print_map(char **arr, t_vars *vars, int row, int col)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	put_img(vars, col, row);
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (img_control(vars, arr, &i, &j))
				break ;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
			x += vars->img_w;
			j++;
		}
		x = 0;
		y += vars->img_h;
		i++;
	}
}
