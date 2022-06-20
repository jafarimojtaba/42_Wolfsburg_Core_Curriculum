/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/20 12:50:10 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *p)
{
	t_philo	*ph;
	t_rules	*r;
	int		i;

	i = 0;
	ph = (t_philo *)p;
	r = ph->rules;
	while (r->all_ate < r->nb_philo && !check_death(r))
	{
		if ((ph->id % 2) && !i)
			usleep((r->time_eat) * 1000);
		i = 1;
		check_death(r);
		living(ph);
		sleeping(ph);
	}
	return (NULL);
}

void	create_thread(t_rules *rules)
{
	t_philo	*ph;
	int		i;

	ph = &(rules->philosophers[0]);
	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(ph[i].p), NULL, &philo_thread, &(ph[i])) != 0)
		{
			printf("could not create thread for philosopher %d", i);
			exit(1);
		}
		i += 1;
	}
	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_join(ph[i].p, NULL) != 0)
		{
			printf("could not join the thread for philosopher %d", i);
			exit(1);
		}
		i += 1;
	}
}

int	main(int argc, char *argv[])
{
	t_rules	rules;
	t_philo	*ph;

	if (argc != 5 && argc != 6)
		return (0);
	rules_init(&rules, argv, argc);
	rules.first_time_stamp = timestamp();
	ph = &(rules.philosophers[0]);
	create_thread(&rules);
	exit_check(&rules);
	return (0);
}
