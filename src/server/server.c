/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:05:48 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/11 14:05:55 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

static void	print_pid()
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
