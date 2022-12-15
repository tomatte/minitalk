/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:59:44 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/14 22:26:02 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

int	main(int argc, char **argv)
{
	args_check(argc, argv);
	response_based_message(argv);
}
