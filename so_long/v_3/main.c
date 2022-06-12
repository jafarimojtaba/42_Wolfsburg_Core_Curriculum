/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:34:27 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/07 10:49:55 by mjafari          ###   ########.fr       */
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

int ft_close ()
{
	exit(0);
}

int key_hook(int keycode, t_vars *vars)
{
	/*ESC*/
	if (keycode == 53)
		ft_close();
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
	// create_map(argv[1], &vars);
	vars.arr = convert_ber_to_arr(argv[1]);
	print_map(vars.arr, &vars, row, colomn);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, 0);
	// printf("collectedc= %d, moves = %d", vars.collected, vars.mc);
	mlx_loop(vars.mlx);
}
