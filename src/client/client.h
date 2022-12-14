#ifndef CLIENT_H
# define CLIENT_H
# include "./libft/libftprintf.h"
# include <signal.h>

//verification and errors
void	die(char *error_msg);
void	args_check(int argc, char **argv);

//signals
void	send_binary_string(char **argv);

//utils
char	*char_to_binary(char c);
char	*binary_8bits_char(char c);

#endif