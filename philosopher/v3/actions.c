/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:03:38 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/13 18:02:58 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_ate(t_philo *ph)
{
	t_rules	*r;

	r = ph->rules;
	if (ph->nb_had_eat >= r->nb_eat && r->nb_eat > 0)
	{
		r->all_ate += 1;
		if (r->all_ate >= r->nb_philo)
		{
			printf("All Philosophers ate their minimum times they should!");
			usleep(10000);
			exit(0);
		}
		return (1);
	}
	else
		return (0);
}

void	eating(t_philo *ph)
{
	t_rules	*r;
	int		t;

	r = ph->rules;
	if (r->f_v[ph->left_fork_id] && r->f_v[ph->right_fork_id])
	{
		r->f_v[ph->left_fork_id] = 0;
		r->f_v[ph->right_fork_id] = 0;
		t = timestamp() - r->first_time_stamp;
		pthread_mutex_lock(&(r->forks[ph->left_fork_id]));
		pthread_mutex_lock(&(r->forks[ph->right_fork_id]));
		printf("%d %d takes a fork\n", t, ph->id);
		printf("%d %d takes a fork\n", t, ph->id);
		printf("%d %d is eating\n", t, ph->id);
		usleep((r->time_eat) * 1000);
		ph->time_last_meal = timestamp();
		ph->nb_had_eat += 1;
	}
	if (r->f_v[ph->left_fork_id] == 0 && r->f_v[ph->right_fork_id] == 0)
	{
		r->f_v[ph->left_fork_id] = 1;
		r->f_v[ph->right_fork_id] = 1;
		pthread_mutex_unlock(&(r->forks[ph->right_fork_id]));
		pthread_mutex_unlock(&(r->forks[ph->left_fork_id]));
	}
}
