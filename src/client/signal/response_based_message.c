/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response_based_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:48:20 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/15 16:38:00 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

t_data	data;

void	init_some_vars(char **argv)
{
	ft_memset(&data, 0, sizeof(data));
	data.pid = ft_atoi(argv[1]);
	data.binary = get_binary_str(argv[2]);
}

static void	signal_handling(int signum)
{
	if (signum != SIGUSR1)
		return ;
	usleep(50);
	if (!data.binary[data.i])
		exit(0);
	if (data.binary[data.i] == '0')
		kill(data.pid, SIGUSR1);
	else
		kill(data.pid, SIGUSR2);
	data.i++;
}

void	response_based_message(char **argv)
{
	init_some_vars(argv);
	if (data.binary[data.i] == '0')
		kill(data.pid, SIGUSR1);
	else
		kill(data.pid, SIGUSR2);
	data.i++;
	signal(SIGUSR1, signal_handling);
	while (1)
		;
}
