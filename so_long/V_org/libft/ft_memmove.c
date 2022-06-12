/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:41:11 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/25 14:25:55 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The  memmove() function copies n bytes from memory area src to memory area
	dest. The memory areas may overlap: copying takes place as though the bytes
	in src are first copied into a temporary array that does not overlap src
	or dest, and the bytes are then copied from the temporary array to dest.
RETURN VALUE
	The memmove() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (!dest || !src)
		return (NULL);
	if (src > dest)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			*(unsigned char *)(dest + i - 1) = *(unsigned char *)(src + i - 1);
			i--;
		}
	}
	return (dest);
}
