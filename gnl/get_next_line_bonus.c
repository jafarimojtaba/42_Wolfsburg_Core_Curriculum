/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:28:18 by mjafari           #+#    #+#             */
/*   Updated: 2021/08/10 08:32:52 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_check_line(int fd, char *buf[fd], char *line[1])
{
	int	i;

	i = 0;
	while (line[0][i])
	{
		if (line[0][i] == '\n')
		{
			if (line[0][i + 1])
				ft_strlcpy (buf[fd], &line[0][i + 1], BUFFER_SIZE + 1);
			else
				ft_bzero (buf[fd], BUFFER_SIZE);
			if (line[0][i + 1] == '\0')
			{
				free(buf[fd]);
				buf[fd] = NULL;
			}
			line[0][i + 1] = '\0';
			return (1);
		}
		i++;
	}
	ft_bzero (buf[fd], BUFFER_SIZE);
	return (0);
}

int	ft_buf_to_line(int fd, char *buf[fd], char *line[1])
{
	int		ret;
	int		len;
	char	*temp;

	ret = 1;
	if (!buf[fd][0])
		ret = read(fd, buf[fd], BUFFER_SIZE);
	if (buf[fd][0])
	{
		len = ft_strlen(line[0]);
		temp = ft_calloc((BUFFER_SIZE + len + 1), sizeof(char));
		temp[BUFFER_SIZE + len] = 0;
		ft_strlcpy(temp, line[0], len + 1);
		ft_strlcat(temp, buf[fd], BUFFER_SIZE + len + 1);
		free(line[0]);
		line[0] = temp;
	}
	return (ret);
}

char	*ft_check_for_free1(int fd, char *buf[fd], int ret, char *line[1])
{
	free(line[0]);
	*line = NULL;
	if ((!buf[fd][0] && ret == 0 ) || (!buf[fd][0] && ret == -1))
	{
		free(buf[fd]);
		buf[fd] = NULL;
	}
	return (NULL);
}

char	*ft_check_for_free2(int fd, char *buf[fd], int ret, char *line[1])
{
	if (buf[fd] && ret == 0)
	{
		free(buf[fd]);
		buf[fd] = NULL;
	}
	return (line[0]);
}

char	*get_next_line(int fd)
{
	static char	*buf[FD_SIZE];
	char		*line[1];
	int			line_c;
	int			ret;

	if (fd < 0 || fd > FD_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf[fd])
		buf[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line[0] = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (1)
	{
		ret = ft_buf_to_line(fd, buf, line);
		if (ret == -1 || (*line[0] == 0 && ret == 0))
			return (ft_check_for_free1(fd, buf, ret, line));
		line_c = ft_check_line(fd, buf, line);
		if (line_c == 1 || ret == 0)
			return (ft_check_for_free2(fd, buf, ret, line));
	}
	return (NULL);
}
