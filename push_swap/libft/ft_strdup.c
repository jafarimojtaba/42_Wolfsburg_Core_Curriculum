/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:29:27 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/25 21:20:42 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strdup() function returns a pointer to a new string which is a
	duplicate of the string s. Memory for the new string is obtained with
	malloc(3), and can be freed with free(3).

	"42 Wolfsburg coding school"
	"42 Wolfsburg coding school"
*/

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_s;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	new_s = malloc((len + 1) * sizeof(char));
	if (new_s != 0)
	{
		while (*(s + i) && i < len)
		{
			*(new_s + i) = *(s + i);
			i++;
		}
		if (len + 1 != 0)
			*(new_s + i) = '\0';
	}
	return (new_s);
}
