/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:46:25 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/19 18:15:53 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;
	size_t	temp[20000];

	dest2 = (char *)dest;
	src2 = (char *)src;
	i = 0;
	while (i < n)
	{
		temp[i] = src2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		*dest2++ = temp[i];
		ft_bzero(&temp[i], 1);
		i++;
	}
	return (dest2);
}
