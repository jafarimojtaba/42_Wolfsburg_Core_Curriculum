/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:19:56 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/29 19:15:06 by mjafari          ###   ########.fr       */
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
		pthread_mutex_unlock(&ph->meal);
		exit(0);
	}
	pthread_mutex_unlock(&ph->meal);
	return(0);
}
