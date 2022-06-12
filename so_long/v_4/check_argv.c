/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:12:37 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/08 20:20:44 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argv(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(&str[len - 4], ".ber", 5) != 0)
	{
		write(1, "Error\nNot a correct .ber file!\n", 32);
		exit(0);
	}
}
