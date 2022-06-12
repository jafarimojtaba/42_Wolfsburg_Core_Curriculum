/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:34:27 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/08 16:42:55 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_error(char *msg)
{
	printf("ERROR\n %s", msg);
	exit(0);
}

int	ft_close(void)
{
	exit(0);
}

void	check_wall(char *str, int line_num)
{
	static int	init_size;
	static int	c;
	int			i;

	i = ft_strlen(str) - 1;
	if (c == 0)
		init_size = i;
	c++;
	if (i != init_size)
		handle_error("not rectangular map!");
	if (line_num == 0)
	{	
		while (i >= 0)
		{
			if (str[i] != '1' && str[i] != 10)
				handle_error("not surounded by walls!");
			i--;
		}
	}
	else if (str[0] != '1' || (str[i] == '\n' && str[i - 1] != '1')
		|| (str[i] != '\n' && str[i] != '1'))
		handle_error("not surounded by walls!");
}

void	first_check(char **map, int *col, int *row)
{
	int	i;

	i = 0;
	*col = ft_strlen(map[0]) - 1;
	while (i < *row - 1)
	{
		check_wall(map[i], i);
		i++;
	}
	check_wall(map[i], 0);
	if (*row < 4 || *col < 4)
		handle_error("not enough rows and columns!");
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	static int	row;
	static int	col;

	if (argc != 2)
		return (0);
	vars.collected = 0;
	vars.mc = 0;
	vars.cc = 0;
	vars.ec = 0;
	vars.pc = 0;
	check_argv(argv[1]);
	vars.arr = convert_ber_to_arr(argv[1], &row);
	first_check(vars.arr, &col, &row);
	map_pec(&vars, vars.arr, col, row);
	vars.mlx = mlx_init();
	print_map(vars.arr, &vars, row, col);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, 0);
	mlx_loop(vars.mlx);
}
