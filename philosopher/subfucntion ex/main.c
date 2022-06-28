#include "philo.h"

void add_up(int *i, t_philo *ph)
{
	pthread_mutex_lock(&ph->update);
	//if we use mutex from shared it makes problem in data racing but 
	//if we use mutex from each thread then it looks fine
	// pthread_mutex_lock(&ph->shared->update);
	(*i)++;
	pthread_mutex_unlock(&ph->update);
	// pthread_mutex_unlock(&ph->shared->update);
}
void *routine(void *p)
{
	t_philo *ph;

	ph = (t_philo *)p;
	for (size_t j = 0; j < 10000; j++)
	{
		add_up(&ph->shared->i, ph);
	}
	
	return (NULL);
}

int main(void)
{
	t_philo p1;
	t_philo p2;
	t_shared sh;
	sh.i = 0;
	pthread_mutex_init(&p1.update, NULL);
	pthread_mutex_init(&p2.update, NULL);
	p1.shared = &sh;
	p2.shared = &sh;
	pthread_create(&p1.p, NULL, &routine, &p1);
	pthread_create(&p2.p, NULL, &routine, &p1);
	pthread_join(p1.p, NULL);
	pthread_join(p2.p, NULL);
	printf("%d",p1.shared->i)
}