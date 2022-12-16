/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_to_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:52:32 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/16 15:23:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

void	signal_handling(int signum, siginfo_t *info, void *ucontext)
{
	static char	c = 0;
	static char	i = 0;

	usleep(50);
	i++;
	if (signum == SIGUSR2)
		c += ft_pow(2, 8 - i);
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	listen_to_signal(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handling;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(50);
}
