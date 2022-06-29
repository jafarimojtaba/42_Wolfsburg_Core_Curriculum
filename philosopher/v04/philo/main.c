/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/29 23:06:07 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *p)
{
	t_philo		*ph;
	int	i;

	i = 0;
	ph = (t_philo *)p;
	while (!sim_end(ph))
	{
		if ((ph->id % 2) && !i)
		while ((current_time(ph) - ph->last_meal_time) < ph->eat_time)
			sim_end(ph);
		i = 1;
		// sim_end(ph);
		if(living(ph))
			sleeping(ph);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_philo	*ph;
	t_shared sh;

	if (argc != 5 && argc != 6)
		return (0);
	shared_init(&sh, ft_atoi(argv[1]));
	ph = sh.philo;
	philos_init(ph, &sh, argv, argc);
	create_thread(ph, ft_atoi(argv[1]));
	return (0);
}
