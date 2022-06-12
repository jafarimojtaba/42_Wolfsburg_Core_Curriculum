/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/12 19:33:27 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *fork_pick(void*  p)
{
	t_philo *ph;
	t_rules *r;
	int		i;

	
	ph = (t_philo *)p;
	r = ph->rules;
	if (r->nb_eat == ph->nb_had_eat && r->nb_eat > 0)
	{
		r->all_ate += 1;
		if (r->all_ate == r->nb_eat)
		{
			printf("All Philosophers ate their minimum times they should!");
			exit(0);
		}
		return (NULL);
	}
	if (r->f_v[ph->left_fork_id] && r->f_v[ph->right_fork_id])
	{
		r->f_v[ph->left_fork_id] = 0;
		r->f_v[ph->right_fork_id] = 0;
		i = timestamp() - r->first_time_stamp;
		pthread_mutex_lock(&(r->forks[ph->left_fork_id]));
		pthread_mutex_lock(&(r->forks[ph->right_fork_id]));
		printf("%d %d takes a fork\n", i,  ph->id);
		printf("%d %d takes a fork\n", i,  ph->id);
		printf("%d %d is eating\n", i, ph->id);
		usleep(r->time_eat);
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
	return (NULL);
}

int	main(int argc , char *argv[])
{
	t_rules	rules;
	int		i;

	i = 0;
	if (argc != 5 && argc != 6)
		return(0);
	rules_init(&rules, argv, argc);
	rules.first_time_stamp = timestamp();
	while (i < rules.nb_philo)
	{
		pthread_create(&(rules.philosophers[i].p), NULL, &fork_pick, &(rules.philosophers[i]));
		i++;
	}
	i = 0;
	while (i < rules.nb_philo)
	{
		pthread_join(rules.philosophers[i].p, NULL);
		i++;
	}
	return (0);
}