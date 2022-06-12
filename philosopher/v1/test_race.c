/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_race.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:30:37 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/10 11:36:26 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* routine(int *n)
{
	for (int i =0; i < 10000; i++)
		(*n)++;
		usleep(1000);
}

int main(int argc, char **argv)
{
	int n = 0;
	pthread_t t1, t2;
	pthread_create(&t1, NULL, &routine, &n);
	pthread_create(&t2, NULL, &routine, &n);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("number of n = %d\n", n);

	return 0;
}