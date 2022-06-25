/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:29:58 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/25 19:25:00 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_philo
{
	pthread_t		p;
	int				nb_philos;
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	long long		start_time;
	long long		last_meal_time;
	int				nb_must_eat;
	int				nb_had_eat;
	int				flag_ate_enough;
	int				flag_died;
	pthread_mutex_t fork;
	pthread_mutex_t update;
	pthread_mutex_t write;
}				t_philo;

long		ft_atoi(const char *str);
// void		mutex_init(t_rules *r);
// void		philo_init(t_rules *r);
void		philos_init(t_philo *r, char *argv[], int argc, pthread_mutex_t *m);
long long	timestamp(void);
int			check_all_ate(t_philo *ph);
int			living(t_philo *ph);
void		print_action(t_philo *ph, char *str);
int			current_time(t_philo *ph);
int			check_death(t_philo *ph);
void		sleeping(t_philo *ph);
// void		mutex_des(t_rules *r);
// void		exit_check(t_rules *r);
// int 		sim_end(t_rules *r);
void		create_thread(t_philo *ph);
void		*philo_thread(void *p);
void 		philo_detach(t_philo *ph);
// void 		exit_free(t_rules *r);

#endif