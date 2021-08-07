/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:28:54 by mjafari           #+#    #+#             */
/*   Updated: 2021/08/07 18:26:26 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = NULL;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
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
		return ((void *)dest2);
	i = 0;
	while (i < c)
	{
		dest2[i] = src2[i];
		i++;
	}
	return ((void *)dest2);
}
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

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
	dest[i] = '\0';
	return (c);
}
