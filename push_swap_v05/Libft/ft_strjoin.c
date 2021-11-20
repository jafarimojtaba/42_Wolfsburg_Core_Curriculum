/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:13:48 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/31 17:24:38 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new_str = (char *)malloc(i + j + 1);
	if (!new_str)
		return (0);
	new_str[i + j] = '\0';
	ft_memmove(new_str, s1, i);
	ft_memmove(&new_str[i], s2, j);
	return (new_str);
}
