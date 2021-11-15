/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:01:59 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/30 13:09:35 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	if (!s)
		return (0);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s, i + 1);
	return (str);
}
