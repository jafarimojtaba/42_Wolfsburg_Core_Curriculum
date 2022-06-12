/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:38:56 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/26 14:17:13 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.

	"42 wolfsburg is the best" 
	16, 8
	"the best"
*/

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*new_s;

	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	new_s = malloc((len + 1) * sizeof(char));
	if (new_s != 0)
		ft_strlcpy(new_s, s + start, len + 1);
	return (new_s);
}
