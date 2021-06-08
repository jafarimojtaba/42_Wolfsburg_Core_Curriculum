/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 23:20:19 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/08 10:00:05 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_str(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i < len && little[j])
			{
				if (big[i] != little[j])
					break ;
				j++;
				i++;
			}
			if (little[j] == '\0')
				return (&(big[i - j]));
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	char	*r;

	b = (char *)big;
	l = (char *)little;
	if (ft_strlen(little) == 0)
		return (b);
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	if (len < ft_strlen(little) || !len)
		return (0);
	r = make_str(b, l, len);
	return (r);
}
