/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:31:42 by mjafari           #+#    #+#             */
/*   Updated: 2022/02/23 23:36:03 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void handle_error(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(1);
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
		handle_error("Given map is not rectangular!");
	if (line_num == 0)
		while (i >= 0)
		{
			if (str[i] != '1' && str[i] != 10)
				handle_error("Given map is not surrounded by walls!");
			i--;
		}
	else if (str[0] != '1' || (str[i] == '\n' && str[i - 1] != '1') ||
			 (str[i] != '\n' && str[i] != '1'))
		handle_error("Given map is not surrounded by walls!");
}

void first_check(char *map)
{
	int fd;
	char *str;
	char *tmp;
	int line_num = 0;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	column = ft_strlen(str) - 1;
	while (str)
	{
		check_wall(str, line_num);
		line_num++;
		tmp = str;
		str = get_next_line(fd);
		row++;
	}
	check_wall(tmp, 0);
	if (row < 4 || column < 4)
		handle_error("Given map is smaller than 4 X 4!");
	close(fd);
}

char **file_to_array(char *map_ber)
{
	int x;
	int y;
	int fd;
	char t[2];
	char **map_array;

	x = 0;
	y = 0;
	fd = open(map_ber, O_RDONLY);
	map_array = (char **)calloc(row, sizeof(char *));
	while (y < row)
		map_array[y++] = (char *)calloc(column, sizeof(char));
	y = 0;
	while (y < row)
	{
		while (x < column)
		{
			read(fd, &(map_array[y][x]), 1);
			if (map_array[y][x++] == 'P')
			{
				if (x_p != 0 || y_p != 0)
					handle_error("Multiple Players are not allowed!");
				x_p = x - 1;
				y_p = y;
			}
		}
		read(fd, t, 1);
		y++;
		x = 0;
	}
	close(fd);
	return map_array;
}