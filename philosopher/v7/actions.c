/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:03:38 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/18 18:06:46 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_action(t_philo *ph, char *str)
{
	t_rules *r;
	int t;

	r = ph->rules;
	pthread_mutex_lock(&(r->write));
	t = timestamp() - r->first_time_stamp;
	printf("%d	%d	%s\n", t, ph->id + 1, str);
	
	pthread_mutex_unlock(&(r->write));
}

int check_death(t_rules *r)
{
	int i;

	pthread_mutex_lock(&r->forks[207]);
	i = 0;
	while (i < r->nb_philo)
	{
		if ((current_time(r) - (r->philosophers[i].time_last_meal)) >= (r->time_die))
		{
			print_action(&r->philosophers[i], "died");
			exit(0);
		}
		i++;
	}
	pthread_mutex_unlock(&r->forks[207]);
	return (0);
}

void living(t_philo *ph)
{
	t_rules *r;

	r = ph->rules;
	if (((timestamp() - ph->time_last_meal) < (r->time_eat + r->time_sleep)) || ph->ate_enough == 1)
		return;
	if (ph->id % 2)
		usleep((r->time_eat) * 1000);
	pthread_mutex_lock(&(r->forks[ph->left_fork_id]));
	print_action(ph, "has taken a fork");
	pthread_mutex_lock(&(r->forks[ph->right_fork_id]));
	print_action(ph, "has taken a fork");
	print_action(ph, "is eating");
	usleep((r->time_eat) * 1000);
	ph->time_last_meal = current_time(r);
	ph->nb_had_eat += 1;
	if ((ph->nb_had_eat == r->nb_eat) && r->nb_eat > 0)
	{
		r->all_ate += 1;
		ph->ate_enough = 1;
	}
	pthread_mutex_unlock(&(r->forks[ph->left_fork_id]));
	pthread_mutex_unlock(&(r->forks[ph->right_fork_id]));
	if (r->all_ate == r->nb_philo)
		exit(0);
	print_action(ph, "is sleeping");
	usleep((r->time_sleep) * 1000);
	print_action(ph, "is thinking");
}