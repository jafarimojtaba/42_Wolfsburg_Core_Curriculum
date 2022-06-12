/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:26:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/11 17:59:42 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *fork(void*  p)
{
	t_philo ph;

	ph = *(t_philo *)p;
	pthread_mutex_lock(&mutex);
	if (ph.[i] != 0 && fork[i + 1] != 0 && i >= 0 && i <=6)
	{
		printf("philosopher %d takes %d and %d\n", i, fork[i], fork[i+1]);
		fork[i]= 0;
		fork[i +1] = 0;
	}
	else if(i == 7 && fork[0] != 0 && fork[i] !=0)
		{
			printf("philosopher %d takes %d and %d\n", i, fork[i], fork[i+1]);
		fork[i]= 0;
		fork[0] = 0;
		}
	else
		printf("philosopher %d has no forks\n", i);
	// else if(i >= 0 && i <8)
	// {
	// 	while (fork[i] == 0 && i < 8)
	// 	{
	// 		i++;
	// 		if (i == 8)
	// 			i = 0;
	// 	}
	// 	i++;
	// 	printf("test from thread %d\n", fork[i]);
	// 	fork[i]= 0;
	// }
	pthread_mutex_unlock(&mutex);
	free(n);
	return (0);
}
void	philo_init(t_philo *ph, char *argv[], int argc)
{
	int i;

	i = 0;
	ph->np = ft_atoi(argv[1]);
	ph->p = (pthread_t *)malloc(ph->np * sizeof (pthread_t));
	ph->f = (int *)malloc(ph->np * sizeof(int));
	if (!(ph->p) || !(ph->f))
		perror("Could not malloc for philosophers or forks!");
	while (i < ph->f)
		ph.f[i] = ++i;
	ph->td = ft_atoi(argv[2]);
	ph->te = ft_atoi(argv[3]);
	ph->ts = ft_atoi(argv[4]);
	if (argc > 5)
		ph->ne = ft_atoi(argv[5]);
}
int	main(int argc , char *argv[])
{
	t_philo	ph;
	int			i;
	if (argc < 5)
		return(0);
	philo_init(&ph, argv, argc);
	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < ph.np; (i)++)
	{
		ph.tmp = malloc(sizeof(int));
		*ph.tmp = i;
		pthread_create(&(ph.p[i]), NULL, &fork, &ph);
	}
	for (i = 0; i < ph.np; (i)++)
	{
		pthread_join(ph.p[i], NULL);
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}