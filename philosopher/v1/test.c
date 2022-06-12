/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:52:51 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/10 11:16:49 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* routine(int n)
{
	printf("test from thread %d\n", n);
	sleep(1);
	printf("Ending thread %d\n", n);
}

int main(int argc, char **argv)
{
	pthread_t t1, t2, t3, t4, t5, t6;
	pthread_create(&t1, NULL, &routine, 1);
	pthread_create(&t2, NULL, &routine, 2);
	pthread_create(&t2, NULL, &routine, 3);
	pthread_create(&t2, NULL, &routine, 4);
	pthread_create(&t2, NULL, &routine, 5);
	pthread_create(&t2, NULL, &routine, 6);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	pthread_join(t5, NULL);
	pthread_join(t6, NULL);
	return 0;
}