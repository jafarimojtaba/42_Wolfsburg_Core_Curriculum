/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:19:56 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/28 20:21:59 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *ph)
{
	int	i;
	int t;
	
	i = 0;
	while (i < ph->nb_philos)
	{
		t = current_time(&ph[i]);
		pthread_mutex_lock(&ph[i].life);
		if ((t - ((&ph[i])->last_meal_time))
			>= ((&ph[i])->die_time))
		{
			print_action(ph, "died");
			pthread_mutex_unlock(&ph[i].life);
			exit(0);
		}
		pthread_mutex_unlock(&ph[i].life);
		i++;
	}
	return (0);
}

int check_all_ate(t_philo *ph)
{
	int	i;
	int c;

	if (ph->nb_must_eat < 1)
	 return (0);
	pthread_mutex_lock(&ph->meal);
	i = 0;
	c = 0;
	while (i < ph->nb_philos)
	{
		if(ph[i++].flag_ate_enough)
			c++;
	}
	if (c == ph->nb_philos)
	{
		// printf("ate enough!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		pthread_mutex_unlock(&ph->meal);
		// pthread_mutex_lock(&ph->shared->update);
		exit(0);
	}
		// r->all_ate = 1;
	pthread_mutex_unlock(&ph->meal);
	// if (c == r->nb_philo)
	// 	return(1);
	return(0);
}

// int sim_end(t_rules *r)
// {
// 	if (r->all_ate || r->died)
// 		return (1);
// 	return (0);
// }