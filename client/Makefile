CC = 		gcc
CFLAGS =	-Wall -Werror -Wextra -I./include
LDFLAGS =	-L./libmy -lmy
NAME =		my_slack_clt
SRC =		my_memset.c \
			my_implode.c \
			my_explode.c \
			client.c \
			main.c
LIB_NAME =	libmy.a
OBJS =		$(SRC:%.c=%.o)
RM =		rm -f

all:			$(LIB_NAME) $(OBJS) $(NAME)

$(LIB_NAME):
				make -C ./libmy

$(NAME):		$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			make fclean -C ./libmy
			$(RM) $(NAME)

.PHONY:			all clean fclean

re:				fclean all

%.o:%.c
			$(CC) $(CFLAGS) -c $<
