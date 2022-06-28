#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

struct s_shared;

typedef struct	s_philo
{
	pthread_t		p;
	pthread_mutex_t update;
	struct s_shared *shared;
}				t_philo;

typedef struct s_shared
{
	int i;
	pthread_mutex_t update;

} t_shared;

#endif