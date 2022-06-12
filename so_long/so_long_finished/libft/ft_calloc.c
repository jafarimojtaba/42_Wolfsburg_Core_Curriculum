/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:13:37 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/25 14:05:08 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;

	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}
