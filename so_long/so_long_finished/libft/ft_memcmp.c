/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:32:07 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/25 14:22:48 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	" + ASCII value of first unmached character of str1 is greater than str2"
	" - ASCII value of first unmached character of str1 is less than str2"
	" 0 Both the string str1 and str2 are equal"
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
