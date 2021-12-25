/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:05:53 by mjafari           #+#    #+#             */
/*   Updated: 2021/12/25 13:37:34 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void usr_handler(int delivery, siginfo_t *siginfo, void *context)
{
	static int delivered = 0;

	(void)siginfo;
	(void)context;
	if (delivery == SIGUSR1)
		delivered++;
	if (delivery == SIGUSR2)
	{
		write(1, "delivered: ", 11);
		ft_putnbr_fd(delivered, 1);
		write(1, "\n", 1);
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
	static int sent;
	char c;
	int i;
	int j;

	j = 0;
	if (argc != 3)
		return (0);
	while (argv[2][j])
	{
		c = argv[2][j];
		i = 7;
		while (i > -1)
		{
			if (c & 1)
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			c = c >> 1;
			i--;
			usleep(100);
		}
		sent++;
		j++;
	}
	i = 8;
	while (i > 0)
	{
		kill(ft_atoi(argv[1]), SIGUSR2);
		i--;
		usleep(100);
	}
	sent++;
	write(1, "sent: ", 6);
	write(1, ft_itoa(sent), sent / 10 + 1);
	write(1, "\n", 1);
	sa.sa_sigaction = usr_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}