/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/29 19:14:34 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *p)
{
	t_philo		*ph;
	int	i;

	i = 0;
	ph = (t_philo *)p;
	while (!check_death(ph) && !check_all_ate(ph))
	{
		if ((ph->id % 2) && !i)
		while ((current_time(ph) - ph->last_meal_time) < ph->eat_time)
			check_death(ph);
		i = 1;
		check_death(ph);
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
