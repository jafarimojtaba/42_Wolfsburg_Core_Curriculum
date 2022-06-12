/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:18:25 by mjafari           #+#    #+#             */
/*   Updated: 2021/12/31 02:42:06 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_bit(char *str, pid_t pid)
{
	static int c;
	int t;
	static int i = 8;
	static char *s;
	static pid_t s_pid;

	if (str)
	{
		s = str;
		s_pid = pid;
	}
	if (i > 0)
	{
		c = *s;
		t = c >> --i;
		if (t & 1)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		if (*s && i == 0)
		{
			i = 8;
			s++;
		}
	}
}

void handler(int sigint, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (sigint == SIGUSR2)
	{
		ft_putstr_fd("Acknoledgment: OK\n", 1);
		exit(0);
	}
	else
		send_bit(0, 0);
}

int main(int argc, char *argv[])
{
	struct sigaction sa;

	if (argc != 3)
		return (0);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_bit(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
