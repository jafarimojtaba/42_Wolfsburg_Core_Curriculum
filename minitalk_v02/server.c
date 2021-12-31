/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:06:08 by mjafari           #+#    #+#             */
/*   Updated: 2021/12/31 02:42:09 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int sigint, siginfo_t *siginfo, void *context)
{
	(void)context;

	static int r;
	static int j;

	r = r << 1;
	if (sigint == SIGUSR1)
		r = r | 1;
	if (++j == 8)
	{
		ft_putchar_fd(r, 1);
		if (r == 0)
		{
			write(1, "\n", 1);
			kill(siginfo->si_pid, SIGUSR2);
		}
		r = 0;
		j = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

int main()
{
	struct sigaction sa;
	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
