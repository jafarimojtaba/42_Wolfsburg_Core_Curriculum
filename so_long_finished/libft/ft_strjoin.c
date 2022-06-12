/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:05:08 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/26 23:09:42 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Allocates (with malloc(3)) and returns a new string, which is the result
	of the concatenation of ’s1’ and ’s2’.
	
	"Ehsan "
	"know how to code"
	"Ehsan know how to code"
*/

#include "libft.h"
#include <stdlib.h>

int	ft_strjoin(char **s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!*s1)
		free(*s1);
	if (!s2)
		free(s2);
	if (!*s1 || !s2)
		return (0);
	i = ft_strlen(*s1);
	j = ft_strlen(s2);
	new_str = (char *)malloc(i + j + 1);
	if (!new_str)
		return (0);
	new_str[i + j] = '\0';
	ft_memmove(new_str, *s1, i);
	ft_memmove(&new_str[i], s2, j);
	free(*s1);
	*s1 = new_str;
	free(s2);
	return (1);
}
