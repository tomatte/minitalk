/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response_based_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:48:20 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/17 18:23:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

t_data	g_data;

static void	kill_or_die(int pid, int signum)
{
	int	err;

	if (pid == 0)
	{
		ft_printf("PID 0 is not allowed! Program exited.\n");
		free(g_data.binary);
		exit(1);
	}
	err = kill(pid, signum);
	if (err)
	{
		ft_printf("Failed to send signal. Program exited.\n");
		free(g_data.binary);
		exit(err);
	}
}

static void	init_some_vars(char **argv)
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
		kill_or_die(g_data.pid, SIGUSR1);
	else
		kill_or_die(g_data.pid, SIGUSR2);
	g_data.i++;
}

void	response_based_message(char **argv)
{
	init_some_vars(argv);
	if (g_data.binary[g_data.i] == '0')
		kill_or_die(g_data.pid, SIGUSR1);
	else
		kill_or_die(g_data.pid, SIGUSR2);
	g_data.i++;
	signal(SIGUSR1, signal_handling);
	while (1)
		;
}
