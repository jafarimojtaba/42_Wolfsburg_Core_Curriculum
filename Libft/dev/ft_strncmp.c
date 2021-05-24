/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:58:26 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/24 15:06:02 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*s11;
	char	*s22;
	size_t	i;

	s11 = (char *)s1;
	s22 = (char *)s2;
	i = 0;
	while (i < n && s11[i] == s22[i] && s11[i] && s22[i])
		i++;
	return ((int)(s11[i] - s22[i]));
}
