/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:44:15 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/31 12:32:54 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long int		i;
	long int		c;
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	c = (long int)n;
	if (src2 == dest2 || c == 0)
		return (dest2);
	i = 0;
	while (i < c)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
