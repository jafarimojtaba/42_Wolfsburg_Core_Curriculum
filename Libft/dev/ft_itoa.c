/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:40:03 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/30 23:02:20 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
