/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:27:32 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/19 23:09:52 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*src2;
	char	*dest2;

	src2 = (char *)src;
	dest2 = (char *)dest;
	i = 0;
	while (i < n && src2[i] != c)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (&dest2[++i]);
}
