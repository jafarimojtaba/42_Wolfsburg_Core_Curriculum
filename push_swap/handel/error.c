/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:11:45 by mjafari           #+#    #+#             */
/*   Updated: 2021/11/13 17:40:37 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	atoi_error(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

	/*
**if two number are equal return 0 else 1
*/
int	numcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (s1[0] == '+')
		s1++;
	if (s2[0] == '+')
		s2++;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (s1[i] == s2[i] && s1[i])
		i++;
	if (s1[i] != '\0')
		return (1);
	return (0);
}

/*
**rules: all integer, no duplicate,
*/
int	is_valid(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i <= argc - 1)
	{		
		j = 0;
		if (argv[i][0] == '+' || argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		j = i + 1;
		while (j <= argc - 1)
		{
			if (numcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
