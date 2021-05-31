/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:34:48 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/31 19:43:22 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_str;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len - 1)
	{
		sub_str = malloc(1 * sizeof(char));
		if (!sub_str)
			return (0);
		return (sub_str);
	}
	else
	{
		sub_str = malloc((len + 1) * sizeof(char));
		if (!sub_str)
			return (0);
		ft_strlcpy(sub_str, &s[start], len + 1);
	}
	return (sub_str);
}
