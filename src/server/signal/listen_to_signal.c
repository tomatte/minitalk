/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_to_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:52:32 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/14 11:29:55 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

void	signal_handling(int signum)
{
	static char	c = 0;
	static char	i = 0;

	i++;
	if (signum == SIGUSR2)
		c += ft_pow(2, 8 - i);
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

void	listen_to_signal()
{
	signal(SIGUSR1, signal_handling);
	signal(SIGUSR2, signal_handling);
	while (1)
		;
}
