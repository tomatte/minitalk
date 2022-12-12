/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:59:44 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/12 13:36:20 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

int	main(int argc, char **argv)
{
	args_check(argc, argv);
	if (argv[2][0] == '0')
		send_sigusr1(argv);
	else
		send_sigusr2(argv);
	return (0);
}
