/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:40:24 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/24 18:17:39 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_rules *rules)
{
	t_philo	*ph;
	int		i;

	ph = &(rules->philosophers[0]);
	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(ph[i].p), NULL, &philo_thread, &(ph[i])) != 0)
		{
			printf("could not create thread for philosopher %d", i);
			exit_free(rules);
			exit(1);
		}
		i += 1;
	}
	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_join(ph[i].p, NULL) != 0)
		{
			printf("could not join the thread for philosopher %d", i);
			exit_free(rules);
			exit(1);
		}
		i += 1;
	}
}

void philo_detach(t_rules *r)
{
	int	i;

	i = 0;
	while (i < r->nb_philo)
	{
		if (pthread_detach(r->philosophers[i].p) != 0)
		{
			printf("could not detach the thread for philosopher %d", i);
			exit_free(r);
			exit(1);
		}
		i += 1;
	}
	free(r->philosophers);
	free(r->forks);
}

void exit_free(t_rules *r)
{
	pthread_mutex_lock(&r->ex);
	// pthread_mutex_lock(&r->write);
	// usleep((r->time_eat) * 1000);
	// mutex_des(r);
	philo_detach(r);
	// pthread_mutex_unlock(&r->write);
	pthread_mutex_unlock(&r->ex);
	
}