/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:07:19 by mjafari           #+#    #+#             */
/*   Updated: 2021/10/19 16:25:47 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_next_c(char *format)
{
	char	*flags;

	flags = "cspdiuxX%";
	if (ft_strchr(flags, *(format + 1)))
		return (1);
	return (0);
}

void	ft_putptr(unsigned long int p, int *count)
{
	if (p > 15)
		ft_putptr(p / 16, count);
	if (p % 16 > 9)
		ft_putchar((p % 16) + 87, count);
	else
		ft_putchar((p % 16) + '0', count);
}

void	ft_check_flag(char *format, va_list args, int *count)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (*format == 'p')
	{
		ft_putstr("0x", count);
		ft_putptr(va_arg(args, unsigned long int), count);
	}
	else if (*format == 'x' || *format == 'X')
		ft_puthex(va_arg(args, unsigned int), count, *format);
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		ft_putnbr(va_arg(args, int), count, *format);
	else if (*format == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *ft, ...)
{
	va_list	args;
	int		count;
	char	*format;

	count = 0;
	va_start(args, ft);
	format = (char *)ft;
	while (*format)
	{
		if (*format == '%' && ft_check_next_c(format))
		{
			format++;
			ft_check_flag(format++, args, &count);
		}
		else
			ft_putchar(*format++, &count);
	}
	va_end(args);
	return (count);
}
