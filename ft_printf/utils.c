/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:09:04 by mjafari           #+#    #+#             */
/*   Updated: 2021/10/19 18:44:35 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr(char *s, int *count)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar(*s++, count);
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == 0 )
		return (&str[i]);
	return (0);
}

void	ft_putnbr(long int n, int *count, char f)
{
	unsigned int	u;

	u = (unsigned int)n;
	if (f == 'u')
	{
		if (u > 9)
			ft_putnbr(u / 10, count, f);
		ft_putchar((u % 10) + '0', count);
	}
	else if (n == -2147483648 && f != 'u')
		ft_putstr("-2147483648", count);
	else if (n < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(-n, count, f);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count, f);
		ft_putchar((n % 10) + '0', count);
	}
	else
		ft_putchar(n + '0', count);
}

void	ft_puthex(unsigned int p, int *count, char f)
{
	if (p > 15)
		ft_puthex(p / 16, count, f);
	if (p % 16 > 9)
	{
		if (f == 'x')
			ft_putchar((p % 16) + 87, count);
		else
			ft_putchar((p % 16) + 55, count);
	}
	else
		ft_putchar((p % 16) + '0', count);
}
