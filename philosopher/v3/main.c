/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/14 20:47:00 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void check_death(t_rules *r)
{
	int		i;

	while (r->all_ate < r->nb_philo)
	{
		i = 0;
		while (i < r->nb_philo && !(r->died))
		{
			if ((timestamp()) - (r->philosophers[i].time_last_meal)> (r->time_die))
			{
				r->died = 1;
				print_action(&r->philosophers[i], "died");
				usleep(150000);
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
	int		i;

	ph = (t_philo *)p;
	r = ph->rules;
	t = timestamp() - r->first_time_stamp;
	while (!(r->died))
	{
		// if(check_all_ate(ph))
		// 	break ;
		i = 0;
		eating(ph, &i);
		if (i && (timestamp() - ph->time_last_meal) > (r->time_die))
		{
			print_action(ph, "is sleeping");
			usleep((r->time_sleep) * 1000);
		}
		print_action(ph, "is thinking");
		check_death(r);
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
		pthread_create(&(rules.philosophers[i].p), NULL, &philo_thread, &(rules.philosophers[i]));
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
