/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response_based_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:48:20 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/16 22:33:03 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

t_data	g_data;

void	init_some_vars(char **argv)
{
	ft_memset(&g_data, 0, sizeof(g_data));
	g_data.pid = ft_atoi(argv[1]);
	g_data.binary = get_binary_str(argv[2]);
}

static void	signal_handling(int signum)
{
	if (signum != SIGUSR1)
		return ;
	if (!g_data.binary[g_data.i])
	{
		free(g_data.binary);
		exit(0);
	}
	if (g_data.binary[g_data.i] == '0')
		kill(g_data.pid, SIGUSR1);
	else
		kill(g_data.pid, SIGUSR2);
	g_data.i++;
}

void	response_based_message(char **argv)
{
	init_some_vars(argv);
	if (g_data.binary[g_data.i] == '0')
		kill(g_data.pid, SIGUSR1);
	else
		kill(g_data.pid, SIGUSR2);
	g_data.i++;
	signal(SIGUSR1, signal_handling);
	while (1)
		;
}
