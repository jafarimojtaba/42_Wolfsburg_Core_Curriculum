/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:58:59 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/01 09:45:13 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		i;

	if (!set || !s1)
		return (0);
	while (ft_strchr(set, *s1) && *s1++)
	{
	}
	if (!*s1 || !*set)
	{
		new_str = malloc(1);
		return (new_str);
	}
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && s1[i--])
	{
	}
	new_str = malloc(i + 2 * sizeof(char));
	if (!new_str)
		return (0);
	ft_strlcpy(new_str, s1, i + 2);
	return (new_str);
}
