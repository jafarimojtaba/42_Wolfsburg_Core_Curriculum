/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 23:02:01 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/30 23:02:26 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnum(long n, int c, char *s)
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
