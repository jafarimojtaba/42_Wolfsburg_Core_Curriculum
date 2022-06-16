/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/16 15:07:12 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_thread(void *p)
{
	
	t_philo *ph;
	t_rules *r;
	int i = 0;;
	// int		t;

	ph = (t_philo *)p;
	r = ph->rules;
	// t = timestamp() - r->first_time_stamp;
	// while (!(r->died) && r->all_ate < r->nb_philo && ph->alive && !ph->ate_enough)
	while (i++ < 5)
	{
	// pthread_mutex_lock(&(((t_philo *)p)->rules->forks[202]));

		// if (check_all_ate(ph))
		// 	break;
		eating(ph);
		// print_action(ph, "is sleeping");
		// usleep((r->time_sleep) * 1000);
		// if ((timestamp() - ph->time_last_meal) < (r->time_die))
		// {
		// 	print_action(ph, "is thinking");
		// }
		// else
		// {
		// 	print_action(ph, "is died");
		// 	exit(0);
		// }
	// pthread_mutex_unlock(&(((t_philo *)p)->rules->forks[202]));

	}
	// check_death(r);

	return (NULL);
}

int main(int argc, char *argv[])
{
	t_rules rules;
	t_philo *ph;
	int i;

	if (argc != 5 && argc != 6)
		return (0);
	rules_init(&rules, argv, argc);
	rules.first_time_stamp = timestamp();
	ph = &(rules.philosophers[0]);
	// printf("%d\n", current_time(&rules));
	// usleep(rules.time_eat * 1000);
	// printf("%d\n", current_time(&rules));
	// printf("time to eat = %d\n", rules.time_eat);
	i = 0;
	while (i < rules.nb_philo)
	{
		if (pthread_create(&(ph[i].p), NULL, &philo_thread, &(ph[i])) != 0)
		{
			printf("could not create thread for philosopher %d", i);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < rules.nb_philo)
	{
		if (pthread_join(ph[i].p, NULL) != 0)
		{
			printf("could not join the thread for philosopher %d", i);
			exit(1);
		}
		i++;
	}
	return (0);
}
