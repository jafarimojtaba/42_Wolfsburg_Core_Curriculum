/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:40:24 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/30 00:00:41 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_philo *ph, int s)
{
	int		i;

	i = 0;
	while (i < s)
	{
		if (pthread_create(&(ph[i].p), NULL, &philo_thread, &(ph[i])) != 0)
		{
			printf("could not create thread for philosopher %d", i);
		}
		i += 1;
	}
	i = 0;
	while (i < s)
	{
		if (pthread_join(ph[i].p, NULL) != 0)
		{
			printf("could not join the thread for philosopher %d", i);
		}
		i += 1;
	}
}
