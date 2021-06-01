/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:43:01 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/01 10:53:26 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_putnbr_fd(int n, int fd)
{
	int		count;
	long	num;
	char	str[12];

	num = n;
	ft_bzero(str, 11);
	count = ft_num_count(num);
	ft_putnum(num, count, str);
	ft_putstr_fd(str, fd);
}
