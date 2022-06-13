/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/13 18:03:08 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void check_death(t_rules *r)
{
	int		i;

	while (r->all_ate < r->nb_philo)
	{
		i = 0;
		while (i < r->nb_philo)
		{
			if (timestamp() - (r->philosophers[i].time_last_meal) > r->time_die)
			{
				r->died = 1;
				printf("died\n");
				usleep(10000);
				exit(0);
			}
			i++;
		}
	}
}

void *philo_thread(void *p)
{
	t_philo *ph;
	t_rules *r;
	int		t;

	ph = (t_philo *)p;
	r = ph->rules;
	t = timestamp() - r->first_time_stamp;
	while (!(r->died))
	{
		if(check_all_ate(ph))
		{
			printf("erroring");
			break ;
		}
		eating(ph);
		printf("%d %d is sleeping\n", t, ph->id);
		usleep((r->time_sleep) * 1000);
		printf("%d %d is thinking\n", t, ph->id);
	}
	// if(check_all_ate(ph))
	// 	return (NULL);
	// eating(ph);

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
		pthread_create(&(rules.philosophers[i].p), NULL, &philo_thread, &(rules.philosophers[i]));
		i++;
	}
	i = 0;
	check_death(&rules);
	while (i < rules.nb_philo)
	{
		pthread_join(rules.philosophers[i].p, NULL);
		i++;
	}
	return (0);
}