/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:32:13 by mjafari           #+#    #+#             */
/*   Updated: 2022/02/24 11:44:24 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isber(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_vars *vars;
    
    if (argc != 2)
        handle_error("more or less argumants?");
    if (isber(argv[1]) == 0)
		handle_error("invalid argument (<name>.ber)");
        
    
}
