/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:34:27 by mjafari           #+#    #+#             */
/*   Updated: 2022/02/04 02:05:27 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

static int row;
static int colomn;

typedef struct s_vars
{
	void *mlx;
	void *win;
	void *img;
} t_vars;

void handle_error(void)
{
	printf("ERROR\n");
	exit(1);
}

int key_hook(int keycode, t_vars *vars)
{
	static int i;
	int width;
	int height;
	static int x=0;
	static int y=0;
	i += 10;
	/*ESC*/
	if (keycode == 53)
		exit(1);
	/*S*/
	if (keycode == 1)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm", &width, &height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
		y = y + height;
	}
	/*D*/
	if (keycode == 2)
	{	
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./imgs/sand.xpm", &width, &height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x , y);
		x += width;
	}
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

int main(void)
{
	t_vars vars;

	first_check("./maps/map2.ber");
	vars.mlx = mlx_init();
	create_map("./maps/map2.ber", &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, 0);
	mlx_loop(vars.mlx);
}
