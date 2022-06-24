/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:35:59 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/24 11:21:49 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_rules *r)
{
	int	i;

	i = r->nb_philo;
	while (--i > -1)
	{
		if (pthread_mutex_init(&(r->forks[i]), NULL) != 0)
		{
			printf("mutex init error in forks!\n");
			exit_check(r);
			exit(1);
		}
	}
	if (pthread_mutex_init(&(r->write), NULL) != 0)
	{
		printf("mutex init error in write!\n");
		exit_check(r);
		exit(1);
	}
}

void	mutex_des(t_rules *r)
{
	int	i;

	i = 210;
	while (--i > -1)
	{
		if (pthread_mutex_destroy(&(r->forks[i])) != 0)
		{
			printf("mutex destroy error in forks!\n");
			exit_check(r);
			exit(1);
		}
	}
	if (pthread_mutex_destroy(&(r->write)) != 0)
	{
		printf("mutex destroy error in write!\n");
		exit_check(r);
		exit(1);
	}
}

void	philo_init(t_rules *r)
{
	int	i;

	i = r->nb_philo;
	r->philosophers = (t_philo *)malloc(i * sizeof(t_philo));
	r->forks = (pthread_mutex_t *)malloc(i * sizeof(pthread_mutex_t));
	while (--i > -1)
	{
		r->philosophers[i].id = i;
		r->philosophers[i].left_fork_id = i;
		r->philosophers[i].right_fork_id = (i + 1) % r->nb_philo;
		r->philosophers[i].time_last_meal = 0;
		r->philosophers[i].nb_had_eat = 0;
		r->philosophers[i].ate_enough = 0;
		r->philosophers[i].rules = r;
		r->philosophers[i].first_time_stamp = r->first_time_stamp;
		if (pthread_mutex_init(&(r->philosophers[i].time), NULL) != 0)
		{
			printf("mutex init error in philo time!\n");
			exit_check(r);
			exit(1);
		}
	}
}

void	rules_init(t_rules *r, char *argv[], int argc)
{
	r->nb_philo = ft_atoi(argv[1]);
	r->time_die = ft_atoi(argv[2]);
	r->time_eat = ft_atoi(argv[3]);
	r->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		r->nb_eat = ft_atoi(argv[5]);
	else
		r->nb_eat = 0;
	r->all_ate = 0;
	philo_init(r);
	mutex_init(r);
}
