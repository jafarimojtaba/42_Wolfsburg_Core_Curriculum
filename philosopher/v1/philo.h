/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:07:46 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/11 16:36:08 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_philo
{
	pthread_t		*p;
	int				*f;
	int				*i;
	int				np;
	int				td;
	int				te;
	int				ts;
	int				ne;
	pthread_mutex_t mutex;
}					t_philo;

int	ft_atoi(const char *str);

#endif