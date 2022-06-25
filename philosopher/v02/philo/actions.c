/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:03:38 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/25 22:10:51 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *ph, char *str)
{
	int		t;

	t = current_time(ph);
	// pthread_mutex_lock(&ph->update);
	// ph->start_time += t % 10;
	// pthread_mutex_unlock(&ph->update);
	pthread_mutex_lock(&(ph->write));
	// t = current_time(ph);
	printf("%d %d %s\n", t, ph->id + 1, str);
	pthread_mutex_unlock(&(ph->write));
}

int	living(t_philo *ph)
{
	int		t;

	if (ph->flag_ate_enough == 1)
		return (0);
	pthread_mutex_lock(&(ph[ph->left_fork_id].fork));
	print_action(ph, "has taken a fork");
	check_death(ph);
	if (ph->nb_philos == 1)
	{
		usleep((ph->die_time) * 1000);
		print_action(ph, "died");
		// exit_free(ph->rules);
		exit(0);
	}
	pthread_mutex_lock(&(ph[ph->right_fork_id].fork));
	print_action(ph, "has taken a fork");
	print_action(ph, "is eating");
	pthread_mutex_lock(&(ph->update));
	ph->last_meal_time = timestamp() - (ph->start_time);
	pthread_mutex_unlock(&(ph->update));
	t = current_time(ph);
	while (current_time(ph) - t < ph->eat_time)
		check_death(ph);
	pthread_mutex_unlock(&(ph[ph->left_fork_id].fork));
	pthread_mutex_unlock(&(ph[ph->right_fork_id].fork));
	return (1);
}

void	sleeping(t_philo *ph)
{
	int		t;

	print_action(ph, "is sleeping");
	pthread_mutex_lock(&(ph->update));
	ph->nb_had_eat += 1;
	pthread_mutex_unlock(&(ph->update));
	if ((ph->nb_had_eat == ph->nb_must_eat) && ph->nb_must_eat > 0)
	{
		pthread_mutex_lock(&(ph->update));
		ph->flag_ate_enough = 1;
		pthread_mutex_unlock(&(ph->update));
	}
	// if (r->all_ate == r->nb_philo)
	// {
	// 	exit_free(r);
	// 	exit(0);
	// }
	t = current_time(ph);
	while ((current_time(ph)) - t < ph->sleep_time)
		check_death(ph);
	print_action(ph, "is thinking");
}
