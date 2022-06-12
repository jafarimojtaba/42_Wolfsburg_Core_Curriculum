/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:32:46 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/06 18:40:04 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(char **arr, t_vars *vars, int row, int col)
{
    int i;
    int j;
    int width;
	int height;
    int x;
	int y;

	x = 0;
	y = 0;
    
    i = 0;
    vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm", &width, &height);
    vars->win = mlx_new_window(vars->mlx, col * width, row * height, "So Long");
    while (i < row)
    {
        j = 0;
        while (j < col)
        {
            if (arr[i][j] == '1')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/wall.xpm", &width, &height);
			else if (arr[i][j] == '0')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm", &width, &height);
			else if (arr[i][j] == 'P')
            {
                vars->p_i = i;
                vars->p_j = j;
                vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm", &width, &height);
            }
			else if (arr[i][j] == 'E')
					vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/helicopter.xpm", &width, &height);
			else if (arr[i][j]== 'C')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/gas.xpm", &width, &height);
			else
				break;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
			x += width;
			j++;
        }
        x = 0;
		y += height;
        i++;
    }
    
}