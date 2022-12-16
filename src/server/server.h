/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:21:02 by coder             #+#    #+#             */
/*   Updated: 2022/12/16 15:22:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "../../libft/libftprintf.h"
# include <signal.h>

//signal
void	listen_to_signal(void);

//utils
char	binary_to_char(char *binary);

#endif