/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:46:25 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/12 15:54:51 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long int		i;
	long int		c;
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	c = (long int)n;
	if (src == dest || c == 0)
		return ((void *)dest2);
	if (dest - src < c && dest - src > 0)
	{
		while (c-- > 0)
			dest2[c] = src2[c];
		return ((void *)dest2);
	}
	i = 0;
	while (i < c)
	{
		dest2[i] = src2[i];
		i++;
	}
	return ((void *)dest2);
}
