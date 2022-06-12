/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:07:46 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/12 17:57:58 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

struct s_rules;

typedef struct		s_philo
{
	pthread_t		p;
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	long long		time_last_meal;
	int				nb_had_eat;
	struct s_rules	*rules;
}					t_philo;

typedef struct s_rules
{
	t_philo				philosophers[210];
	pthread_mutex_t		forks[210];
	int					f_v[250];
	pthread_mutex_t		write;
	int					nb_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	long long			first_time_stamp;
}						t_rules;

int	ft_atoi(const char *str);
void 	mutex_init(t_rules *r);
void	philo_init(t_rules *r);
void	rules_init(t_rules *r, char *argv[], int argc);
long long	timestamp(void);

#endif