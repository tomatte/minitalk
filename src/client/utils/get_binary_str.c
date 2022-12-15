/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:02:40 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/15 12:15:49 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

char	*get_binary_str(char *str)
{
	char	*big;
	char	*binary_char;
	char	*aux;

	
	big = ft_strdup("\0");
	while (*str)
	{
		aux = big;
		binary_char = binary_8bits_char(*str);
		big = ft_strjoin(big, binary_char);
		free(aux);
		free(binary_char);
		str++;
	}
	return (big);
}
