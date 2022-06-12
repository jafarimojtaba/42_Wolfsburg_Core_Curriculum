/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:32:09 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/26 14:16:18 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
	specified in ’set’ removed from the beginning and the end of the string.
	
	"42 wolfsburg is the best 42"
	"42"
	" wolfsburg is the best "
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_s;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)) != 0)
		start++;
	while (end > start && ft_strchr(set, *(s1 + end)) != 0)
		end--;
	new_s = ft_substr(s1, start, end - start + 1);
	return (new_s);
}
