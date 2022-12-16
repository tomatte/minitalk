/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:05:48 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/16 15:22:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

static void	print_pid(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server pid: %d\n", pid);
}

int	main(void)
{
	print_pid();
	listen_to_signal();
	return (0);
}
