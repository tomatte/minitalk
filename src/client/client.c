/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:59:44 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/12 17:19:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

int	main(int argc, char **argv)
{
	args_check(argc, argv);
	send_binary_string(argv);
}
