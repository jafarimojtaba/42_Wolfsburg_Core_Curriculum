/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:07:46 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/20 13:19:41 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

struct	s_rules;

typedef struct s_philo
{
	pthread_t		p;
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	long long		time_last_meal;
	int				nb_had_eat;
	int				ate_enough;
	struct s_rules	*rules;
}					t_philo;

typedef struct s_rules
{
	t_philo				philosophers[210];
	pthread_mutex_t		forks[210];
	pthread_mutex_t		write;
	int					nb_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					all_ate;
	long long			first_time_stamp;
}						t_rules;

long		ft_atoi(const char *str);
void		mutex_init(t_rules *r);
void		philo_init(t_rules *r);
void		rules_init(t_rules *r, char *argv[], int argc);
long long	timestamp(void);
int			check_all_ate(t_philo *ph);
int			living(t_philo *ph);
void		print_action(t_philo *ph, char *str);
int			current_time(t_rules *r);
int			check_death(t_rules *r);
void		sleeping(t_philo *ph);
void		mutex_des(t_rules *r);
void		exit_check(t_rules *rules);
void		unlock_forks(t_rules *r);

#endif