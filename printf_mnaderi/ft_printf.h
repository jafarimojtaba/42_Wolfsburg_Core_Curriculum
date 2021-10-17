/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaderi <mnaderi@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:15:56 by mnaderi           #+#    #+#             */
/*   Updated: 2021/09/29 15:03:18 by mnaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putchar(char c, int *chars_printed);

void	ft_putstr(char *s, int *chars_printed);

void	ft_putnbr(int n, int *chars_printed);

void	ft_putnbr_sb(unsigned int n, int *chars_printed, int s_or_b);

void	ft_put_p(unsigned long n, int *chars_printed);

void	ft_putnbr_for_u(unsigned int n, int *chars_printed);

void	make_type(const char *input, va_list vars, int *chars_printed);

int		ft_printf(const char *input, ...);

#endif