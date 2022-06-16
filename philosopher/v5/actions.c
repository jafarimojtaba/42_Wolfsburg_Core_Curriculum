/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:03:38 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/16 14:37:04 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *ph, char *str)
{
	t_rules	*r;
	int		t;

	r = ph->rules;
	t = timestamp() - r->first_time_stamp;
	pthread_mutex_lock(&(r->write));
	printf("%d	%d %s\n", t, ph->id + 1, str);
	pthread_mutex_unlock(&(r->write));
}
int	check_all_ate(t_philo *ph)
{
	t_rules	*r;

	r = ph->rules;
	printf("number of all ate is = %d\n", r->all_ate);
	if (ph->nb_had_eat >= r->nb_eat && r->nb_eat > 0)
	{
		if (ph->nb_had_eat == r->nb_eat)
			pthread_detach(ph->p);
		r->all_ate += 1;
		ph->ate_enough = 1;
		if (r->all_ate >= r->nb_philo)
		{
			printf("All Philosophers ate their minimum times they should!");
			usleep(10000);
			exit(0);
		}
		return (1);
	}
	else
	{
		return (0);
	}
}

void check_death(t_rules *r)
{
	int		i;

	while (r->all_ate < r->nb_philo)
	{
		i = 0;
		while (i < r->nb_philo && !(r->died))
		{
			if ((timestamp()) - (r->philosophers[i].time_last_meal)> (r->time_die))
			{
				r->died = 1;
				print_action(&r->philosophers[i], "died");
				usleep(150000);
				exit(0);
			}
			i++;
		}
	}
}

void	eating(t_philo *ph)
{
	t_rules	*r;

	r = ph->rules;
		pthread_mutex_lock(&(r->forks[ph->left_fork_id]));
		printf("%lli	philosopher %d takes fork %d\n", timestamp() - r->first_time_stamp, ph->id, ph->id);
		pthread_mutex_lock(&(r->forks[ph->right_fork_id]));
		printf("%lli	philosopher %d takes fork %d\n", timestamp() - r->first_time_stamp, ph->id, ph->id + 1);
		printf("%lli	philosopher %d is eating\n", timestamp() - r->first_time_stamp, ph->id);
		usleep((r->time_eat) * 1000);
		ph->time_last_meal = timestamp();
		ph->nb_had_eat += 1;
		// if(check_all_ate(ph))
		// 	return;
		pthread_mutex_unlock(&(r->forks[ph->right_fork_id]));
		pthread_mutex_unlock(&(r->forks[ph->left_fork_id]));
}
