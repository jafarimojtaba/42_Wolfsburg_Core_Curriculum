/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/28 20:21:50 by mjafari          ###   ########.fr       */
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
			// usleep((ph->eat_time) * 1000);
		i = 1;
		check_death(ph);
		if(living(ph))
			sleeping(ph);
	}
	// while (i < 5)
	// {
	// 	pthread_mutex_lock(&ph->update);
	// 	i++;
	// 	puts("hi");
	// 	pthread_mutex_unlock(&ph->update);
	// }
	return (NULL);
}

void *end_thread(void *p)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	t_philo		*ph;

	ph = (t_philo *)p;
	usleep((ph->die_time) * 1000);
	while (i < ph[0].nb_philos)
	{
		if ((current_time(&ph[i]) - ph[i].last_meal_time) >= ph[i].die_time)
		{
			print_action(&ph[i], "died");
			exit(0);
		}
		if (ph[i].flag_ate_enough)
		{
			pthread_mutex_lock(&ph->shared->update);
			c++;
			pthread_mutex_unlock(&ph->shared->update);
		}
		if (c == ph->nb_philos)
		{
			exit(0);
		}
	}
	return (0);
}
int	main(int argc, char *argv[])
{
	t_philo	*ph;
	t_shared sh;
	// pthread_t sim_end;
	// pthread_mutex_t mm;

	if (argc != 5 && argc != 6)
		return (0);
	// pthread_mutex_init(&mm,NULL);
	// pthread_mutex_lock(&mm);
	shared_init(&sh, ft_atoi(argv[1]));
	ph = (t_philo *)malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	philos_init(ph, &sh, argv, argc);
	// pthread_mutex_unlock(&mm);
	// sleep(1);
	// ph = &(rules.philosophers[0]);
	create_thread(ph, ft_atoi(argv[1]));
	// sim_end_init(ph, &sim_end);
	// sleep(10);
	// philo_detach(ph);
	// mutex_des(&rules);
	return (0);
}
