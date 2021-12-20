/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:51:14 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/26 14:24:45 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strnstr() function locates the first occurrence of the null-terminated
	string little in the string big, where not more than len characters are
	searched. Characters that appear after a ‘\0’ character are not searched.
	Since the strnstr() function is a FreeBSD specific API, it should only be
	used when portability is not a concern.
	
	"42 Wolfsburg is the best"
	15
	"wolfsborg"
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	little_len = 0;
	while (little[little_len])
		little_len++;
	if (little_len == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] && j < little_len && i + j < len
			&& big[i + j] == little[j])
			j++;
		if (j == little_len)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
