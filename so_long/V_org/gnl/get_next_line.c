/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:28:18 by mjafari           #+#    #+#             */
/*   Updated: 2021/08/07 18:32:55 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_line(char buf[BUFFER_SIZE], char *line[1])
{
	int	i;

	i = 0;
	while (line[0][i])
	{
		if (line[0][i] == '\n')
		{
			if (line[0][i + 1])
				ft_strlcpy (buf, &line[0][i + 1], BUFFER_SIZE + 1);
			else
				ft_bzero (buf, BUFFER_SIZE);
			line[0][i + 1] = '\0';
			return (1);
		}
		i++;
	}
	ft_bzero (buf, BUFFER_SIZE);
	return (0);
}

int	ft_buf_to_line(int fd, char buf[BUFFER_SIZE], char *line[1])
{
	int		ret;
	int		len;
	char	*temp;

	ret = 1;
	if (!buf[0])
		ret = read(fd, buf, BUFFER_SIZE);
	if (buf[0])
	{
		len = ft_strlen(line[0]);
		temp = ft_calloc((BUFFER_SIZE + len + 1), sizeof(char));
		ft_strlcpy(temp, line[0], len + 1);
		ft_strlcat(temp, buf, BUFFER_SIZE + len + 1);
		free(line[0]);
		line[0] = temp;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line[1];
	int			line_c;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[0] = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (1)
	{
		ret = ft_buf_to_line(fd, buf, line);
		if ((ret == -1) || (*line[0] == 0 && ret == 0))
		{	
			free(line[0]);
			*line = NULL;
			return (NULL);
		}
		line_c = ft_check_line(buf, line);
		if (line_c == 1 || ret == 0)
			return (line[0]);
	}
	return (NULL);
}
