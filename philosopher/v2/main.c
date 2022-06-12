/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/12 18:10:30 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *fork_pick(void*  p)
{
	t_philo *ph;
	t_rules *r;

	ph = (t_philo *)p;
	r = ph->rules;
	if (r->f_v[ph->left_fork_id] && r->f_v[ph->right_fork_id])
	{
		r->f_v[ph->left_fork_id] = 0;
		r->f_v[ph->right_fork_id] = 0;
		pthread_mutex_lock(&(r->forks[ph->left_fork_id]));
		printf("philosopher %d takes fork %d\n", ph->id, ph->id);
		pthread_mutex_lock(&(r->forks[ph->right_fork_id]));
		printf("philosopher %d takes fork %d\n", ph->id, ph->id + 1);
		printf("philosopher %d is eating\n", ph->id);
		usleep(r->time_eat);
	}
	if (r->f_v[ph->left_fork_id] == 0 && r->f_v[ph->right_fork_id] == 0)
	{
		r->f_v[ph->left_fork_id] = 1;
		r->f_v[ph->right_fork_id] = 1;
		pthread_mutex_unlock(&(r->forks[ph->right_fork_id]));
		pthread_mutex_unlock(&(r->forks[ph->left_fork_id]));
	}
	return (0);
}

int	main(int argc , char *argv[])
{
	t_rules	rules;
	int		i;

	i = 0;
	if (argc != 5 && argc != 6)
		return(0);
	rules_init(&rules, argv, argc);
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