/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:58:59 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/04 11:53:34 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_c(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		start;
	int		end;

	if (!set || !s1)
		return (0);
	start = 0;
	while (ft_check_c(set, s1[start]) && s1[start])
		start++;
	end = ft_strlen(s1) - 1;
	if (start == end + 1)
	{
		new_str = malloc(1);
		new_str[0] = 0;
		return (new_str);
	}
	while (ft_check_c(set, s1[end]) && s1[end])
		end--;
	new_str = malloc((end - start + 2) * sizeof(char));
	if (!new_str)
		return (0);
	ft_strlcpy(new_str, &s1[start], end - start + 2);
	return (new_str);
}
