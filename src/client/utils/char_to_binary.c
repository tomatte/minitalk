/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:25:29 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/14 09:24:08 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libftprintf.h"

static int	binary_len(char c)
{
	int	i;

	if (!c)
		return (1);
	i = 0;
	while (c)
	{
		c = c / 2;
		i++;
	}
	return (i);
}

char	*char_to_binary(char c)
{
	int		remainder;
	int		len;
	char	*binary;

	if (!c)
		return (NULL);
	len = binary_len(c);
	binary = (char *) malloc(sizeof(char) * (len + 1));
	if (!binary)
		return (NULL);
	binary[len] = '\0';
	while (--len >= 0)
	{
		remainder = c % 2;
		binary[len] = remainder + 48;
		c = c / 2;
	}
	return (binary);
}

char	*binary_8bits_char(char c)
{
	char	*binary_char;
	char	*binary_8bits_char;
	int				left_zeros;

	if (!c)
		return (ft_strdup("00000000"));
	binary_char = char_to_binary(c);
	binary_8bits_char = (char *) malloc(sizeof(char) * 9);
	if (!binary_char || !binary_8bits_char)
		return (NULL);
	ft_strlcpy(binary_8bits_char, "00000000", 9);
	left_zeros = 8 - ft_strlen(binary_char);
	ft_strlcpy(&binary_8bits_char[left_zeros], binary_char, 9 - left_zeros);
	free(binary_char);
	return (binary_8bits_char);
}
