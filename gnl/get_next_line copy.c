/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:06:08 by mjpro             #+#    #+#             */
/*   Updated: 2021/08/05 23:28:57 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_line(char *line, char *buf)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (line[i +1])
				ft_strcpy(buf, &line[i+1]);
			else
				ft_memset(buf, 0 ,BUFFER_SIZE);
			line[++i] = '\0';
			return (1);
		}
		i++;
	}
	ft_memset(buf, 0 ,BUFFER_SIZE);
	return (0);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*line[1];
	static char	*buf[1];
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf[0])
	{
		buf[0] = malloc(BUFFER_SIZE + 1);
		line[0] = malloc(BUFFER_SIZE + 1);
		ret = read(fd, buf[0], BUFFER_SIZE);
		if (!buf[0] || ret == -1 || !line[0])
			return (NULL);
		ft_strcpy(line[0], buf[0]);
		ret = ft_check_line(line[0], buf[0]);
		if (ret)
			return (line[0]);
	}
	else
	{
		line[0] = malloc(BUFFER_SIZE + 1);
		if (!line[0])
			return (NULL);
		ft_strcpy(line[0], buf[0]);
		ret = ft_check_line(line[0], buf[0]);
		if (ret)
			return (line[0]);
	}
	while (1)
	{
		ft_memset(buf[0], 0 ,BUFFER_SIZE);
		ret = read(fd, buf[0], BUFFER_SIZE);
		if (ret == 0)
			break ;
		if (ret == -1)
			return (NULL);
		ret = strlen(line[0]);
		temp = malloc(ret + BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		ft_strcpy(temp, line[0]);
		ft_strcat(temp, buf[0]);
		line[0] = temp;
		ret = ft_check_line(line[0], buf[0]);
		if (ret)
			return (line[0]);
	}
	return (NULL);
}
