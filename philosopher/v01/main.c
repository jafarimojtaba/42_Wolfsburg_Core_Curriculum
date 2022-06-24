/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/24 18:17:21 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *p)
{
	t_philo		*ph;
	t_rules		*r;
	static int	i;

	i = 0;
	ph = (t_philo *)p;
	r = ph->rules;
	while (!sim_end(r) && !check_death(ph))
	{
		if ((ph->id % 2) && !i)
		while ((current_time(ph) - ph->time_last_meal) < r->time_eat)
			check_death(ph);
		i = 1;
		check_death(ph);
		if(living(ph))
			sleeping(ph);
			
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_rules	rules;
	t_philo	*ph;

	if (argc != 5 && argc != 6)
		return (0);
	rules.first_time_stamp = timestamp();
	rules_init(&rules, argv, argc);
	// sleep(1);
	ph = &(rules.philosophers[0]);
	create_thread(&rules);
	philo_detach(&rules);
	mutex_des(&rules);
	return (0);
}
