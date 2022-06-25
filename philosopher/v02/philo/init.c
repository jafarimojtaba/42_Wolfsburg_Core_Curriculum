/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:35:59 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/25 20:52:04 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	mutex_init(t_rules *r)
// {
// 	int	i;

// 	i = r->nb_philo;
// 	while (--i > -1)
// 	{
// 		if (pthread_mutex_init(&(r->forks[i]), NULL) != 0)
// 		{
// 			printf("mutex init error in forks!\n");
// 			exit(1);
// 		}
// 	}
// 	if (pthread_mutex_init(&(r->write), NULL) != 0)
// 	{
// 		printf("mutex init error in write!\n");
// 		exit(1);
// 	}
// 	if (pthread_mutex_init(&(r->ex), NULL) != 0)
// 	{
// 		printf("mutex init error in exit!\n");
// 		exit(1);
// 	}
// 	if (pthread_mutex_init(&(r->meal), NULL) != 0)
// 	{
// 		printf("mutex init error in meal!\n");
// 		exit(1);
// 	}
// 	if (pthread_mutex_init(&(r->life), NULL) != 0)
// 	{
// 		printf("mutex init error in life!\n");
// 		exit(1);
// 	}
// }

// void	mutex_des(t_rules *r)
// {
// 	int	i;

// 	i = r->nb_philo;;
// 	while (--i > -1)
// 	{
// 		if (pthread_mutex_destroy(&(r->forks[i])) != 0)
// 		{
// 			printf("mutex destroy error in forks!\n");
// 			exit(1);
// 		}
// 	}
// 	if (pthread_mutex_destroy(&(r->write)) != 0)
// 	{
// 		printf("mutex destroy error in write!\n");
// 		exit(1);
// 	}
// 	if (pthread_mutex_destroy(&(r->ex)) != 0)
// 	{
// 		printf("mutex destroy error in exit!\n");
// 		exit(1);
// 	}
// 	if (pthread_mutex_destroy(&(r->meal)) != 0)
// 	{
// 		printf("mutex destroy error in meal!\n");
// 		exit(1);
// 	}
// 	if (pthread_mutex_destroy(&(r->life)) != 0)
// 	{
// 		printf("mutex destroy error in life!\n");
// 		exit(1);
// 	}
// }

// void	philos_init(t_rules *r)
// {
// 	int	i;

// 	i = r->nb_philo;
// 	r->philosophers = (t_philo *)malloc(i * sizeof(t_philo));
// 	r->forks = (pthread_mutex_t *)malloc(i * sizeof(pthread_mutex_t));
// 	while (--i > -1)
// 	{
// 		r->philosophers[i].id = i;
// 		r->philosophers[i].left_fork_id = i;
// 		r->philosophers[i].right_fork_id = (i + 1) % r->nb_philo;
// 		r->philosophers[i].time_last_meal = 0;
// 		r->philosophers[i].nb_had_eat = 0;
// 		r->philosophers[i].ate_enough = 0;
// 		r->philosophers[i].rules = r;
// 		r->philosophers[i].first_time_stamp = r->first_time_stamp;
// 		if (pthread_mutex_init(&(r->philosophers[i].time), NULL) != 0)
// 		{
// 			printf("mutex init error in philo time!\n");
// 			exit(1);
// 		}
// 		if (pthread_mutex_init(&(r->philosophers[i].meal), NULL) != 0)
// 		{
// 			printf("mutex init error in philo meal!\n");
// 			exit(1);
// 		}
// 	}
// }

void	philos_init(t_philo *ph, char *argv[], int argc, pthread_mutex_t *m)
{
	int i;
	int t;

	i = 0;
	t = timestamp();
	pthread_mutex_lock(m);
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&(ph[i].fork), NULL);
		pthread_mutex_init(&(ph[i].update), NULL);
		pthread_mutex_init(&(ph[i].write), NULL);
		ph[i].die_time = ft_atoi(argv[2]);
		ph[i].eat_time = ft_atoi(argv[3]);
		ph[i].sleep_time = ft_atoi(argv[4]);
		if (argc == 6)
			ph[i].nb_must_eat = ft_atoi(argv[5]);
		else
			ph[i].nb_must_eat = 0;
		ph[i].id = i;
		ph[i].nb_philos = ft_atoi(argv[1]);
		ph[i].left_fork_id = i;
		ph[i].right_fork_id = (i + 1) % ph->nb_philos;
		pthread_mutex_lock(&ph[i].update);
		ph[i].start_time = t;
		ph[i].last_meal_time = 0;
		pthread_mutex_unlock(&ph[i].update);
		ph[i].nb_had_eat = 0;
		ph[i].flag_ate_enough = 0;
		ph[i].flag_died = 0;
		pthread_mutex_init(&(ph[i].fork), NULL);
		pthread_mutex_init(&(ph[i].update), NULL);
		pthread_mutex_init(&(ph[i].write), NULL);
		i++;
	}
	pthread_mutex_unlock(m);
}
