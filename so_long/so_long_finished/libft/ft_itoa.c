/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:55:03 by mjafari           #+#    #+#             */
/*   Updated: 2021/10/03 17:36:43 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_get_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		pre;
	char	*str;

	len = ft_get_len(n);
	str = malloc((len + 2) * sizeof(char));
	if (str)
	{
		str[len + 1] = '\0';
		pre = 1;
		if (n < 0)
		{
			*str = '-';
			pre = -1;
		}
		str[len] = pre * (n % 10) + '0';
		while (n / 10 != 0)
		{
			n = n / 10;
			len--;
			str[len] = pre * (n % 10) + '0';
		}
	}
	return (str);
}
