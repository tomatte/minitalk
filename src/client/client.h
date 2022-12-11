#ifndef CLIENT_H
# define CLIENT_H
# include "./libft/libftprintf.h"
# include <signal.h>

void	client_test();

//verification and errors
void	die(char *error_msg);
void	args_check(int argc, char **argv);

#endif