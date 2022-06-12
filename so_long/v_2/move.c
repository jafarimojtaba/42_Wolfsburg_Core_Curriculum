/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:21:39 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/06 18:21:33 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(t_vars *vars, int i, int j, int *mc)
{
    vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm", &vars->img_w, &vars->img_h);
    if (vars->arr[i - 1][j] != '1')
    {
        if (vars->arr[i - 1][j] == 'C')
            vars->collected += 1;
        vars->arr[i][j] = '0';
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40 , (i) * 40);
        vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm", &vars->img_w, &vars->img_h);
        if (vars->arr[i - 1][j] == 'E')
            exit(0);
        i -= 1;
        vars->arr[i][j] = 'P';
        vars->p_i = i;
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40 , (i) * 40);
        mc++;
    }
}

void move_down(t_vars *vars, int i, int j, int *mc)
{
    vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm", &vars->img_w, &vars->img_h);
    if (vars->arr[i + 1][j] != '1')
    {
        if (vars->arr[i + 1][j] == 'C')
            vars->collected += 1;
        vars->arr[i][j] = '0';
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40 , (i) * 40);
        vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm", &vars->img_w, &vars->img_h);
        if (vars->arr[i + 1][j] == 'E')
            exit(0);
        i += 1;
        vars->arr[i][j] = 'P';
        vars->p_i = i;
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40 , (i) * 40);
        mc++;
    }
}

void move_right(t_vars *vars, int i, int j, int *mc)
{
    vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm", &vars->img_w, &vars->img_h);
    if (vars->arr[(i)][j + 1] != '1')
    {
        if (vars->arr[i][j + 1] == 'C')
            vars->collected += 1;
        vars->arr[i][j] = '0';
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40 , (i) * 40);
        vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm", &vars->img_w, &vars->img_h);
        if (vars->arr[i][j + 1] == 'E')
            exit(0);
        j += 1;
        vars->arr[i][j] = 'P';
        vars->p_j = j;
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40 , (i) * 40);
        mc++;
    }
}

void move_left(t_vars *vars, int i, int j, int *mc)
{
    vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm", &vars->img_w, &vars->img_h);
    if (vars->arr[(i)][j - 1] != '1')
    {
        if (vars->arr[i][j - 1] == 'C')
            vars->collected += 1;
        vars->arr[i][j] = '0';
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40 , (i) * 40);
        vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm", &vars->img_w, &vars->img_h);
        if (vars->arr[i][j - 1] == 'E')
            exit(0);
        j -= 1;
        vars->arr[i][j] = 'P';
        vars->p_j = j;
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40 , (i) * 40);
        mc++;
    }
}
