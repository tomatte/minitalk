#ifndef CLIENT_H
# define CLIENT_H
# include "../../libft/libftprintf.h"
# include <signal.h>

typedef struct  s_data
{
    int     i;
    int     pid;
    int     first;
    char    *binary;
}   t_data;

//verification and errors
void	die(char *error_msg);
void	args_check(int argc, char **argv);

//signals
void	send_binary_string(char **argv);
void	response_based_message(char **argv);

//utils
char	*char_to_binary(char c);
char	*binary_8bits_char(char c);
char	*get_binary_str(char *str);

#endif