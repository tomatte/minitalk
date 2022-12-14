/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_to_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:52:32 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/12 17:46:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

void	signal_handling(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("0\n");
	else if (signum == SIGUSR2)
		ft_printf("1\n");
}

void	listen_to_signal()
{
	signal(SIGUSR1, signal_handling);
	signal(SIGUSR2, signal_handling);
	while (1)
		;
}
