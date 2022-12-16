/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_to_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:52:32 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/16 22:34:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

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
	kill(info->si_pid, SIGUSR1);
}

void	listen_to_signal(void)
{
	struct sigaction	sa;
	sigset_t            mask;

	sigemptyset(&mask);
	sa.sa_sigaction = signal_handling;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = mask;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
}
