/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:06:08 by mjafari           #+#    #+#             */
/*   Updated: 2021/12/25 13:37:29 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void usr_handler(int bit, siginfo_t *siginfo, void *context)
{
	static int recived = 0;

	static int arr[8];
	static int i;
	int c;

	if (i == 0)
		i = 8;
	if (bit == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	arr[--i] = bit;
	if (i == 0)
	{
		c = 0;
		while (i < 8)
		{
			c = c << 1;
			c = c | arr[i];
			i++;
		}
		write(1, &c, 1);
		recived++;
		ft_bzero(arr, 8);
		if (c == 0)
		{
			while (recived > 0)
			{
				usleep(400);
				kill(siginfo->si_pid, SIGUSR1);
				recived--;
			}
			usleep(800);
			kill(siginfo->si_pid, SIGUSR2);
			write(1, "\n", 1);
		}
	}
	(void)context;
}

int main(void)
{
	struct sigaction sa;

	write(1, "Server_PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sa.sa_sigaction = usr_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}