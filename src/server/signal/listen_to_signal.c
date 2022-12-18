/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_to_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:52:32 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/17 17:44:35 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

static void	kill_or_die(int pid, int signum)
{
	int	err;

	if (pid == 0)
	{
		ft_printf("PID 0 is not allowed! Program exited.\n");
		exit(1);
	}
	err = kill(pid, signum);
	if (err)
	{
		ft_printf("Failed to send signal. Program exited.\n");
		exit(err);
	}
}

void	signal_handling(int signum, siginfo_t *info, void *ucontext)
{
	static char	c = 0;
	static char	i = 0;

	(void) ucontext;
	i++;
	if (signum == SIGUSR2)
		c += ft_pow(2, 8 - i);
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	kill_or_die(info->si_pid, SIGUSR1);
}

void	listen_to_signal(void)
{
	struct sigaction	sa;
	sigset_t			mask;

	sigemptyset(&mask);
	sa.sa_sigaction = signal_handling;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = mask;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
}
