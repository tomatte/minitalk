/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_to_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:52:32 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/11 14:02:31 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

void	signal_handling(int signum)
{
	ft_printf("signal received: %d\n", signum);
}

void	listen_to_signal()
{
	signal(SIGUSR1, signal_handling);
	while (1)
	{
		ft_printf("Waiting for signal...\n");
		sleep(1);
	}
}
