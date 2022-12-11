/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:54:51 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/11 13:23:12 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

static void	arg_count_check(int argc)
{
    if (argc < 3)
        die("Too few arguments.");
    else if (argc > 3)
        die("Too many arguments.");
}

static void	is_only_int(char *arg)
{
    while (*arg)
    {
        if (!ft_isdigit(*arg))
            die("Invalid PID.");
        arg++;
    }
}

static void	arg_verctor_check(char **argv)
{
    is_only_int(argv[1]);
}

void	args_check(int argc, char **argv)
{
    arg_count_check(argc);
    arg_verctor_check(argv);
}
