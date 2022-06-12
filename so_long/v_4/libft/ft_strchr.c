/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:28:14 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/27 11:38:11 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strchr() function returns a pointer to the first occurrence of the
	character c in the string s.

	"42 Wolfsburg coding school"
	'c'
	"coding school"
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (!(char )c && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}
