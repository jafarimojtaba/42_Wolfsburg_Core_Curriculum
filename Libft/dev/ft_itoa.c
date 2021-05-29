/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:40:03 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/28 20:02:48 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnum(long n, int c, char *s)
{
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
		s++;
	}
	while (--c >= 0)
	{
		s[c] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		count;
	long	num;
	char	*str;

	num = n;
	count = ft_num_count(num);
	str = (char *)malloc((count + 2) * sizeof(char));
	ft_putnum(num, count, str);
	return (str);
}
