/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:05:48 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/10 23:21:05 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

int	main(void)
{
    int	pid;

	pid = getpid();
    server_test();
    ft_printf("Server started with pid %d\n", pid);
    return (0);
}