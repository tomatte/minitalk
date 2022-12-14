/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary__to_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:34:59 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/14 11:02:43 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

char	binary_to_char(char *binary)
{
	char	result;
	char	power;
	char	i;

	if (!binary || !*binary)
		return (0);
	power = ft_strlen(binary) - 1;
	result = 0;
	i = 0;
	while (binary[i])
	{
		if (binary[i] == '1')
			result += ft_pow(2, power - i);
		i++;
	}
	return (result);
}
