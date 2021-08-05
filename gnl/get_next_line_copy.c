/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:06:08 by mjpro             #+#    #+#             */
/*   Updated: 2021/08/05 12:37:39 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_check_next_line(char *line, char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
		{
			strcpy(line, &buf[++i]);
			break ;
		}
		i++;
	}
}

int	ft_check_first_line(char *str, char *buf)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			strcpy(buf, &str[i]);
			str[++i] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			ret;
	int			line_len;
	char		*line[1];
	static char	*buf[1];
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf[0])
	{
		ret = strlen(buf[0]);
		line[0] = malloc(BUFFER_SIZE + ret + 1);
		if (!line[0])
			return (NULL);
		ft_check_next_line(line[0], buf[0]);
	}
	while (1)
	{
		if (!buf[0])
		{
			buf[0] = malloc(BUFFER_SIZE + 1);
			line[0] = malloc(BUFFER_SIZE + 2);
			ret = read(fd, buf[0], BUFFER_SIZE);
			if (!buf[0] || ret == -1 || !line[0])
				return (NULL);
			strcat(line[0], buf[0]);
			ret = ft_check_first_line(line[0], buf[0]);
			if (ret)
				return (line[0]);
		}
		ret = read(fd, buf[0], BUFFER_SIZE);
		if (ret == 0)
			break ;
		if (!buf[0] || ret == -1 || !line[0])
			return (NULL);
		line_len = strlen(line[0]);
		temp = malloc(line_len + BUFFER_SIZE + 2);
		if (!temp)
			return (NULL);
		strcpy(temp, line[0]);
		strcat(temp, buf[0]);
		line[0] = temp;
		ret = ft_check_first_line(line[0], buf[0]);
		if (ret)
			return (line[0]);
	}
	return (NULL);
}
