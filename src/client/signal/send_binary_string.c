/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_binary_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:13:40 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/14 09:27:01 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

static void	send_binary_char(int pid, char c)
{
	char	*binary_char;
	int		i;

	binary_char = binary_8bits_char(c);
	if (!binary_char)
		return ;
	i = -1;
	while (binary_char[++i])
	{
		if (binary_char[i] == '0')
			kill(pid, SIGUSR1);
		else if (binary_char[i] == '1')
			kill(pid, SIGUSR2);
		usleep(2);
	}
	free(binary_char);
}

void	send_binary_string(char **argv)
{
	int		i;
	int		pid;
	char	*str;

	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = -1;
	while (str[++i])
		send_binary_char(pid, str[i]);
}
