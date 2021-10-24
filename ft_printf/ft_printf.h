/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:07:32 by mjafari           #+#    #+#             */
/*   Updated: 2021/10/19 15:55:25 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putchar(int c, int *count);

void	ft_putstr(char *s, int *count);

char	*ft_strchr(const char *s, int c);

void	ft_putnbr(long int n, int *count, char f);

void	ft_putptr(unsigned long int p, int *count);

void	ft_puthex(unsigned int p, int *count, char f);

int		ft_printf(const char *format, ...);

#endif
