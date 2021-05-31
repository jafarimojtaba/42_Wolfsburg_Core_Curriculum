/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:43:01 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/30 23:11:37 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		count;
	long	num;
	char	str[11];

	num = n;
	ft_bzero(str, 11);
	count = ft_num_count(num);
	ft_putnum(num, count, str);
	ft_putstr_fd(str, fd);
}
