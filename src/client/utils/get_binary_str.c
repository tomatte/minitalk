/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:02:40 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/16 15:20:32 by coder            ###   ########.fr       */
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
