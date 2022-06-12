/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:39:31 by mjafari           #+#    #+#             */
/*   Updated: 2021/09/26 13:03:55 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The  strncmp() function compares only the first (at most) n bytes of the
	two strings s1 and s2.
	
	" + ASCII value of first unmached character of str1 is greater than str2"
	" - ASCII value of first unmached character of str1 is less than str2"
	" 0 Both the string str1 and str2 are equal"
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || !s1 || !s2)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
