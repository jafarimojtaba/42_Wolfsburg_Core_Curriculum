/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ber_to_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:06:02 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/08 16:31:01 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_rows(int fd, int *row)
{
	char	**arr;
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		(*row)++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (tmp)
		free(tmp);
	close(fd);
	arr = (char **)calloc((*row + 1), sizeof(char *));
	return (arr);
}

char	**convert_ber_to_arr(char *file, int *row_ret)
{
	char	**arr;
	int		fd;
	int		i;
	int		row;

	row = 0;
	fd = open(file, O_RDONLY);
	arr = read_rows(fd, &row);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < row)
	{
		arr[i] = get_next_line(fd);
		i++;
	}
	*row_ret = row;
	close(fd);
	return (arr);
}

void	map_pec(t_vars *vars, char **arr, int col, int row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (!(ft_strchr("10PEC\n", arr[i][j])))
				handle_error("not permitted chars!");
			if (arr[i][j] == 'P')
				(vars->pc)++;
			if (arr[i][j] == 'C')
				(vars->cc)++;
			if (arr[i][j++] == 'E')
				(vars->ec)++;
		}
		i++;
	}
	if (vars->pc != 1 || vars->ec == 0 || vars->cc == 0)
		handle_error("number of player/exit/collectible is/are not correct!");
}
