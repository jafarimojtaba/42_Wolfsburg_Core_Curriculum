/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 23:20:19 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/24 15:06:06 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == 0)
		return ((char *)big);
	while (*big++)
	{
		i = 0;
		if (*big == *little)
		{
			while (i < len && big[i] && little[i])
			{
				if (big[i] != little[i])
					break ;
				i++;
			}
			if (little[i] == 0 || i == len)
				return ((char *)big);
		}
	}
	return (0);
}
