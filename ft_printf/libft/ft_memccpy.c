/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:27:32 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/12 15:56:11 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dest2;
	unsigned char	c2;

	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	c2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest2 = (unsigned char *)ft_memcpy(dest2, src2, 1);
		if (*src2 == c2)
			return ((void *)(++dest2));
		dest2++;
		src2++;
		i++;
	}
	return (0);
}
