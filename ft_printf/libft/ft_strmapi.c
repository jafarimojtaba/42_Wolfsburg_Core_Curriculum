/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:26:41 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/31 19:58:19 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (0);
	i = ft_strlen(s);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str[i] = '\0';
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
