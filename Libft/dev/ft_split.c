/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:38:50 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/05 21:11:12 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(const char *s, int c)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_end(const char *s, int c)
{
	int	i;

	if (!(*s))
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static void	ft_putarr(char **new_array, char const *s, char c, int count)
{
	int	i;
	int	end;

	i = 0;
	while (count-- > 0)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			end = ft_end(s, c);
			new_array[i] = ft_substr(s, 0, end);
			if (!new_array[i])
				free(new_array[i]);
			i++;
			s += end;
		}
	}
	while (i < count)
		new_array[i++] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**new_array;
	char	*temp;
	char	p[1];
	int		count;

	if (!s || !c)
		return (0);
	p[0] = c;
	temp = ft_strtrim(s, p);
	if (ft_strlen(temp) == 0)
	{
		new_array = (char **)malloc(1 * sizeof(char *));
		if (!new_array)
			return (0);
		new_array[0] = 0;
		return (new_array);
	}
	count = ft_counter(temp, c);
	new_array = (char **)malloc((count + 1) * sizeof(char *));
	if (!new_array)
		return (0);
	new_array[count] = 0;
	ft_putarr(new_array, temp, c, count);
	free(temp);
	return (new_array);
}
