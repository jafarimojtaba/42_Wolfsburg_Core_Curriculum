/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:19:56 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/27 20:45:18 by mjafari          ###   ########.fr       */
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
		pthread_mutex_lock(&ph[i].update);
		if ((t - ((&ph[i])->last_meal_time))
			>= ((&ph[i])->die_time))
		{
			print_action(ph, "died");
			pthread_mutex_unlock(&ph[i].update);
			exit(0);
		}
		pthread_mutex_unlock(&ph[i].update);
		i++;
	}
	return (0);
}

// int check_all_ate(t_philo *ph)
// {
// 	int	i;
// 	int c;

// 	if (r->nb_eat < 1)
// 	 return (0);
// 	pthread_mutex_lock(&r->meal);
// 	i = 0;
// 	c = 0;
// 	while (i < r->nb_philo)
// 	{
// 		if(r->philosophers[i++].ate_enough)
// 			c++;
// 	}
// 	if (c == r->nb_philo)
// 		r->all_ate = 1;
// 	pthread_mutex_unlock(&r->meal);
// 	if (c == r->nb_philo)
// 		return(1);
// 	return(0);
// }

// int sim_end(t_rules *r)
// {
// 	if (r->all_ate || r->died)
// 		return (1);
// 	return (0);
// }