/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/25 20:55:36 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *p)
{
	t_philo		*ph;
	int	i;

	i = 0;
	ph = (t_philo *)p;
	while (!check_death(ph))
	{
		if ((ph->id % 2) && !i)
		while (((current_time(ph)) - ph->last_meal_time) < ph->eat_time)
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
	pthread_mutex_t main_mutex;

	ph = (t_philo *)malloc(ft_atoi(argv[1]) *sizeof(t_philo));
	if (argc != 5 && argc != 6)
		return (0);
	pthread_mutex_init(&main_mutex, NULL);
	philos_init(ph, argv, argc, &main_mutex);
	// sleep(1);
	// ph = &(rules.philosophers[0]);
	create_thread(ph);
	philo_detach(ph);
	// mutex_des(&rules);
	return (0);
}
