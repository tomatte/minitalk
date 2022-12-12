/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:13:40 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/12 13:20:56 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

void	send_sigusr1(char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
}

void	send_sigusr2(char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR2);
}

