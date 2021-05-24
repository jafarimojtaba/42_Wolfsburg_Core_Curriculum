/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:28:17 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/24 18:55:07 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	if (nmemb * size == 0 || nmemb * size > 2147483647)
		return (0);
	ptr = (unsigned char *)malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size);
	return (ptr);
}
