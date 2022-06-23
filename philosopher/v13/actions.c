/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:03:38 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/23 18:41:11 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *ph, char *str)
{
	t_rules	*r;
	int		t;

	r = ph->rules;
	pthread_mutex_lock(&(r->write));
	ph->first_time_stamp += current_time(ph) % 10;
	t = current_time(ph);
	printf("%d %d %s\n", t, ph->id + 1, str);
	pthread_mutex_unlock(&(r->write));
}

int	check_death(t_philo *ph)
{
		if ((current_time(ph) - (ph->time_last_meal))
			>= (ph->rules->time_die))
		{
			print_action(ph, "died");
			exit(0);
		}
	return (0);
}

int	living(t_philo *ph)
{
	t_rules	*r;
	int		t;

	r = ph->rules;
	if (ph->ate_enough == 1)
		return (0);
	pthread_mutex_lock(&(r->forks[ph->left_fork_id]));
	print_action(ph, "has taken a fork");
	ph->time_last_meal = current_time(ph);
	if (r->nb_philo == 1)
	{
		usleep((r->time_die) * 1000);
		print_action(ph, "died");
		exit(0);
	}
	pthread_mutex_lock(&(r->forks[ph->right_fork_id]));
	print_action(ph, "has taken a fork");
	print_action(ph, "is eating");
	t = current_time(ph);
	while (current_time(ph) - t < r->time_eat)
		check_death(ph);
	pthread_mutex_unlock(&(r->forks[ph->left_fork_id]));
	pthread_mutex_unlock(&(r->forks[ph->right_fork_id]));
	return (1);
}

void	sleeping(t_philo *ph)
{
	t_rules	*r;
	int		t;

	r = ph->rules;
	print_action(ph, "is sleeping");
	ph->nb_had_eat += 1;
	if ((ph->nb_had_eat == r->nb_eat) && r->nb_eat > 0)
	{
		pthread_mutex_lock(&r->m_all_ate);
		r->all_ate += 1;
		pthread_mutex_unlock(&r->m_all_ate);
		ph->ate_enough = 1;
	}
	if (r->all_ate == r->nb_philo)
		exit(0);
	t = current_time(ph);
	while (current_time(ph) - t < r->time_sleep)
		check_death(ph);
	print_action(ph, "is thinking");
}
