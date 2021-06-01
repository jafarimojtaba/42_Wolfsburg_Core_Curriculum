/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:40:03 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/01 10:51:54 by mjafari          ###   ########.fr       */
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
		s[c] = 0;
	}
	while (--c >= 0)
	{
		s[c] = (n % 10) + '0';
		n = n / 10;
	}
}

static int	ft_num_count(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		count;
	long	num;
	char	*str;

	num = n;
	count = ft_num_count(num);
	if (num < 0)
	{
		str = malloc((count + 2) * sizeof(char));
		if (!str)
			return (0);
	}
	else
	{
		str = malloc((count + 1) * sizeof(char));
		if (!str)
			return (0);
		str[count] = 0;
	}
	ft_putnum(num, count, str);
	return (str);
}
