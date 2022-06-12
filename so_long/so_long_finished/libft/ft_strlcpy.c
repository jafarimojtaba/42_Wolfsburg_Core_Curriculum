/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:37:00 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/26 01:24:17 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len])
		len++;
	i = 0;
	while (*(src + i) && i + 1 < size)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (size != 0)
		*(dst + i) = '\0';
	return (len);
}
