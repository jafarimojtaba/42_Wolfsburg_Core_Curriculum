/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:19:56 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/30 00:20:16 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *ph)
{
	int	i;
	int	t;

	i = 0;
	while (i < ph->nb_philos)
	{
		t = current_time(&ph[i]);
		pthread_mutex_lock(&ph[i].life);
		if ((t - ((&ph[i])->last_meal_time)) >= ((&ph[i])->die_time))
		{
			print_action(ph, "died", current_time(ph));
			pthread_mutex_lock(&ph->shared->update);
			ph->shared->flag_die = 1;
			pthread_mutex_unlock(&ph->shared->update);
		}
		pthread_mutex_unlock(&ph[i].life);
		i++;
	}
	return (0);
}

int	check_all_ate(t_philo *ph)
{
	int	i;
	int	c;

	if (ph->nb_must_eat < 1)
		return (0);
	pthread_mutex_lock(&ph->meal);
	i = 0;
	c = 0;
	while (i < ph->nb_philos)
	{
		if (ph[i++].flag_ate_enough)
			c++;
	}
	if (c == ph->nb_philos)
	{
		pthread_mutex_lock(&ph->shared->update);
		ph->shared->flag_ate = 1;
		pthread_mutex_unlock(&ph->shared->update);
	}
	pthread_mutex_unlock(&ph->meal);
	return (0);
}

int	sim_end(t_philo *ph)
{
	pthread_mutex_lock(&ph->shared->update);
	if (ph->shared->flag_ate || ph->shared->flag_die)
	{
		pthread_mutex_unlock(&ph->shared->update);
		return (1);
	}
	pthread_mutex_unlock(&ph->shared->update);
	if (!check_all_ate(ph) && !check_death(ph))
		return (0);
	return (1);
}
