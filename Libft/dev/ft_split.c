/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:38:50 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/31 19:59:40 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(const char *s, int c)
{
	int	count;

	count = 1;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

static int	ft_end(const char *s, int c)
{
	int	i;

	if (!(*s))
		return (0);
	i = 1;
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
			new_array[i++] = ft_substr(s, 0, end);
			s += end;
		}
	}
	while (i < count)
		new_array[i++] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**new_array;
	int		count;

	if (!s || !c)
		return (0);
	if (ft_strlen(s) == 0)
	{
		new_array = (char **)malloc(1 * sizeof(char *));
		if (!new_array)
			return (0);
		new_array[0] = 0;
		return (new_array);
	}
	count = ft_counter(s, c);
	new_array = (char **)malloc((count + 1) * sizeof(char *));
	if (!new_array)
		return (0);
	new_array[count] = 0;
	ft_putarr(new_array, s, c, count);
	return (new_array);
}
