/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:15:02 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/05 13:14:53 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (size < i || size == 0)
	{
		return (j + size);
	}
	c = i + j;
	j = 0;
	while (i < size - 1 && src[j])
	{
		dest[i++] = src[j++];
	}
	dest[i] = 0;
	return (c);
}
