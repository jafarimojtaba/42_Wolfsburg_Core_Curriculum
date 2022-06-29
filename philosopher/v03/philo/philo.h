/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:29:58 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/29 17:45:00 by mjafari          ###   ########.fr       */
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

struct s_shared;

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
	struct s_shared *shared;
	pthread_mutex_t update;
	pthread_mutex_t meal;
	pthread_mutex_t life;
	pthread_mutex_t time;
}				t_philo;

typedef struct	s_shared
{
	t_philo			*philo;
	pthread_mutex_t *fork;
	pthread_mutex_t write;
	pthread_mutex_t update;
	pthread_mutex_t life;
	int				flag_die;
	int				flag_ate;
}				t_shared;


long		ft_atoi(const char *str);
void		philos_init(t_philo *ph, t_shared *sh, char *argv[], int argc);
void		shared_init(t_shared *sh, int s);
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
void		create_thread(t_philo *ph, int s);
void		*philo_thread(void *p);
void 		philo_detach(t_philo *ph);
void 		*end_thread(void *p);
void		sim_end_init(t_philo *ph, pthread_t *sim_end);
void 		exit_free(t_philo *ph);

#endif