#------------------- server ------------------------

SRC_SERVER			=	listen_to_signal.c \


OBJS_DIR_SERVER		=	objects_server

OBJS_SERVER			=	$(patsubst %.c,objects_server/%.o, $(SRC_SERVER))

NAME_SERVER			=	server_exec

#---------------------------------------------------

#------------------- client ------------------------

SRC_CLIENT			=	args_check.c \
						die.c \
						char_to_binary.c \
						send_binary_string.c \



OBJS_DIR_CLIENT		=	objects_client

OBJS_CLIENT			=	$(patsubst %.c,objects_client/%.o, $(SRC_CLIENT))

NAME_CLIENT			=	client_exec

#---------------------------------------------------

LIBFT		=	./libft/libftprintf.a

CFLAGS		=	-I./ -Wall -Werror -Wextra

NAME		=	minitalk

VPATH				=	./src/client/test \
						./src/server/test \
						./src/client/verification_and_errors \
						./src/server/signal \
						./src/client/signal \
						./src/client/utils \

$(OBJS_DIR_SERVER)/%.o:	%.c
							$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_CLIENT)/%.o:	%.c
							$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(OBJS_DIR_SERVER):
						mkdir -p $@

$(OBJS_DIR_CLIENT):
						mkdir -p $@

$(NAME_SERVER): $(OBJS_DIR_SERVER) $(OBJS_SERVER) $(LIBFT)
	cc ./src/server/server.c ${OBJS_SERVER} ${CFLAGS} ${LIBFT} -o $@

$(NAME_CLIENT): $(OBJS_DIR_CLIENT) $(OBJS_CLIENT) $(LIBFT)
	cc ./src/client/client.c ${OBJS_CLIENT} ${CFLAGS} ${LIBFT} -o $@
	
$(NAME): $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C ./libft bonus

clean:
	rm -rf ${OBJS_DIR_SERVER} ${OBJS_DIR_CLIENT}
	make -C ./libft clean

fclean:	clean
	rm -f ${NAME_SERVER} ${NAME_CLIENT}
	make -C ./libft fclean

re: fclean all

.PHONY:	all clean fclean re