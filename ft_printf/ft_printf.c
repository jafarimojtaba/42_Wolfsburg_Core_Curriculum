/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:53:51 by mjafari           #+#    #+#             */
/*   Updated: 2021/10/14 13:05:17 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdarg.h"
#include "stdio.h"
#include <string.h>
#include "./libft/libft.h"

int	ft_printf(const char *format,...)
{
    va_list args;
    char *c;
    int i = 0;
    
    // write(1, format, 18);
    puts(format);
    printf("%ld\n", strlen(format));
    va_start(args, format);
    c = va_arg(args, char *);
    // write(1, c, 21);
    puts(c);
    printf("%ld\n", strlen(c));
    c = va_arg(args, char *);
    // write(1, c, 21);
    puts(c);
    printf("%ld\n", strlen(c));
    // va_end(args);
    c = va_arg(args, char *);
    // write(1, c, 21);
    puts(c);
    printf("%ld\n", strlen(c));
    return c;
}