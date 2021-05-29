/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:38:50 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/28 18:09:20 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(const char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s && *s == c)
			count++;
		s++;
	}
	return (++count);
}

static int	ft_end(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**new_array;
	int		n;
	int		i;
	int		count;

	i = 0;
	n = 0;
	count = ft_counter(s, c);
	new_array = (char **) malloc ((count + 1) * sizeof (char *));
	if (!new_array)
		return (0);
	new_array[count] = '\0';
	while (count-- > 0)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			n = ft_end(s, c);
			new_array[i++] = ft_substr(s, 0, n);
			s += n;
		}
	}
	return (new_array);
}
