/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:15:02 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/21 19:21:24 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	c = i;
	size += i;
	while (i < size - 1 && src[j])
	{
		dest[i++] = src[j++];
	}
	dest[i] = 0;
	while (src[j])
	{
		j++;
	}
	return (j + c);
}
