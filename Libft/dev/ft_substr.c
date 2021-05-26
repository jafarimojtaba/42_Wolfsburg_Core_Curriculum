/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:34:48 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/26 00:30:24 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_str;

	s_len = ft_strlen(s);
	if (start > s_len - 1)
		return (0);
	if (s_len - start >= len)
	{
		sub_str = (char *)malloc(len + 1);
		sub_str[len] = '\0';
	}
	else
	{
		sub_str = (char *)malloc(s_len - start + 1);
		sub_str[s_len - start] = '\0';
	}
	if (!sub_str)
		return (0);
	ft_memmove(sub_str, &s[start], len);
	return (sub_str);
}
