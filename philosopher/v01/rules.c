/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:19:56 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/24 18:17:43 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *ph)
{
		if ((current_time(ph) - (ph->time_last_meal))
			>= (ph->rules->time_die))
		{
			pthread_mutex_lock(&(ph->rules->life));
			ph->rules->died = 1;
			print_action(ph, "died");
			exit_free(ph->rules);
			pthread_mutex_unlock(&(ph->rules->life));
			exit(0);
		}
	return (0);
}

int check_all_ate(t_rules *r)
{
	int	i;
	int c;

	if (r->nb_eat < 1)
	 return (0);
	pthread_mutex_lock(&r->meal);
	i = 0;
	c = 0;
	while (i < r->nb_philo)
	{
		if(r->philosophers[i++].ate_enough)
			c++;
	}
	if (c == r->nb_philo)
		r->all_ate = 1;
	pthread_mutex_unlock(&r->meal);
	if (c == r->nb_philo)
		return(1);
	return(0);
}

int sim_end(t_rules *r)
{
	if (r->all_ate || r->died)
		return (1);
	return (0);
}