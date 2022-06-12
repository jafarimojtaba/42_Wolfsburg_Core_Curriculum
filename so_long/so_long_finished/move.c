/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:21:39 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/08 16:40:37 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars, int i, int j)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm",
			&vars->img_w, &vars->img_h);
	if (vars->arr[i - 1][j] == 'E' && vars->cc != vars->collected)
		return ;
	if (vars->arr[i - 1][j] != '1')
	{
		if (vars->arr[i - 1][j] == 'C')
			vars->collected += 1;
		vars->arr[i][j] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40,
			(i) * 40);
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm",
				&vars->img_w, &vars->img_h);
		if (vars->arr[i - 1][j] == 'E' && vars->cc == vars->collected)
			exit(0);
		i -= 1;
		vars->arr[i][j] = 'P';
		vars->p_i = i;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40,
			(i) * 40);
		vars->mc += 1;
		ft_putstr_fd(((ft_itoa)(vars->mc)), 1);
		write(1, "\n", 1);
	}
}

void	move_down(t_vars *vars, int i, int j)
{
	if (vars->arr[i + 1][j] == 'E' && vars->cc != vars->collected)
		return ;
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm",
			&vars->img_w, &vars->img_h);
	if (vars->arr[i + 1][j] != '1')
	{
		if (vars->arr[i + 1][j] == 'C')
			vars->collected += 1;
		vars->arr[i][j] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40,
			(i) * 40);
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm",
				&vars->img_w, &vars->img_h);
		if (vars->arr[i + 1][j] == 'E' && vars->cc == vars->collected)
			exit(0);
		i += 1;
		vars->arr[i][j] = 'P';
		vars->p_i = i;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40,
			(i) * 40);
		vars->mc += 1;
		ft_putstr_fd(((ft_itoa)(vars->mc)), 1);
		write(1, "\n", 1);
	}
}

void	move_right(t_vars *vars, int i, int j)
{
	if (vars->arr[i][j + 1] == 'E' && vars->cc == vars->collected)
		return ;
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm",
			&vars->img_w, &vars->img_h);
	if (vars->arr[(i)][j + 1] != '1')
	{
		if (vars->arr[i][j + 1] == 'C')
			vars->collected += 1;
		vars->arr[i][j] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40,
			(i) * 40);
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm",
				&vars->img_w, &vars->img_h);
		if (vars->arr[i][j + 1] == 'E' && vars->cc == vars->collected)
			exit(0);
		j += 1;
		vars->arr[i][j] = 'P';
		vars->p_j = j;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40,
			(i) * 40);
		vars->mc += 1;
		ft_putstr_fd(((ft_itoa)(vars->mc)), 1);
		write(1, "\n", 1);
	}
}

void	move_left(t_vars *vars, int i, int j)
{
	if (vars->arr[i][j - 1] == 'E' && vars->cc != vars->collected)
		return ;
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm",
			&vars->img_w, &vars->img_h);
	if (vars->arr[(i)][j - 1] != '1')
	{
		if (vars->arr[i][j - 1] == 'C')
			vars->collected += 1;
		vars->arr[i][j] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40,
			(i) * 40);
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm",
				&vars->img_w, &vars->img_h);
		if (vars->arr[i][j - 1] == 'E' && vars->cc == vars->collected)
			exit(0);
		j -= 1;
		vars->arr[i][j] = 'P';
		vars->p_j = j;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 40,
			(i) * 40);
		vars->mc += 1;
		ft_putstr_fd(((ft_itoa)(vars->mc)), 1);
		write(1, "\n", 1);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_close();
	if (keycode == 13)
		move_up(vars, vars->p_i, vars->p_j);
	if (keycode == 1)
		move_down(vars, vars->p_i, vars->p_j);
	if (keycode == 2)
		move_right(vars, vars->p_i, vars->p_j);
	if (keycode == 0)
		move_left(vars, vars->p_i, vars->p_j);
	return (0);
}
