/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:34:27 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/06 20:45:10 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

static int row;
static int colomn;

void handle_error(void)
{
	printf("ERROR\n");
	exit(1);
}

int key_hook(int keycode, t_vars *vars)
{
	/*ESC*/
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
		move_up(vars, vars->p_i, vars->p_j, &vars->mc);
	if (keycode == 1)
		move_down(vars, vars->p_i, vars->p_j, &vars->mc);
	if (keycode == 2)
		move_right(vars, vars->p_i, vars->p_j, &vars->mc);
	if (keycode == 0)
		move_left(vars, vars->p_i, vars->p_j, &vars->mc);
	return (0);
}

void check_wall(char *str, int line_num)
{
	static int init_size;
	static int c;
	int i;

	i = ft_strlen(str) - 1;
	if (c == 0)
		init_size = i;
	c++;
	if (i != init_size)
		handle_error();
	if (line_num == 0)
		while (i >= 0)
		{
			if (str[i] != '1' && str[i] != 10)
				handle_error();
			i--;
		}
	else if (str[0] != '1' || (str[i] == '\n' && str[i - 1] != '1') ||
			 (str[i] != '\n' && str[i] != '1'))
		handle_error();
}

void first_check(char *map)
{
	int fd;
	char *str;
	char *tmp;
	int line_num = 0;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	colomn = ft_strlen(str) - 1;
	while (str)
	{
		check_wall(str, line_num);
		line_num++;
		tmp = str;
		str = get_next_line(fd);
		free(tmp);
		row++;
	}
	check_wall(tmp, 0);
	if (row < 4 || colomn < 4)
		handle_error();
	close(fd);
}
void create_map(char *map, t_vars *vars)
{
	int fd;
	char *str;
	char *tmp;
	int width;
	int height;
	int x;
	int y;
	int v;

	x = 0;
	y = 0;
	v = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/wall.xpm", &width, &height);
	printf("width: %d, height:%d", width, height);
	vars->win = mlx_new_window(vars->mlx, colomn * width, row * height, "So Long");
	while (str)
	{
		tmp=str;
		while (*str)
		{
			if (*str == '1')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/wall.xpm", &width, &height);
			else if (*str == '0')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm", &width, &height);
			else if (*str == 'P')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/player.xpm", &width, &height);
			else if (*str == 'E')
				{
					vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/helicopter.xpm", &width, &height);
					v++;	
				}
			else if (*str == 'C')
			{
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/gas.xpm", &width, &height);
				v++;
			}
			else
				break;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
			x += width;
			str++;
		}
		free(tmp);
		x = 0;
		y += height;
		str = get_next_line(fd);
	}
}

int ft_close ()
{
	exit(0);
}

int main(int argc, char **argv)
{
	t_vars vars;

	if (argc != 2)
		return(0);
	vars.collected = 0;
	vars.mc = 0;
	check_argv(argv[1]);
	first_check(argv[1]);
	vars.mlx = mlx_init();
	create_map(argv[1], &vars);
	// vars.arr = convert_ber_to_arr(argv[1]);
	// print_map(vars.arr, &vars, row, colomn);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, 0);
	// printf("collectedc= %d, moves = %d", vars.collected, vars.mc);
	mlx_loop(vars.mlx);
}
