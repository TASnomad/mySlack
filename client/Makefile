##
## Makefile for MySlack in /home/nomad/mySlack/client
## 
## Made by BARREAU Martin
## Login   <barrea_m@etna-alternance.net>
## 
## Started on  Sun Feb 18 22:29:20 2018 BARREAU Martin
## Last update Sun Feb 18 23:05:42 2018 BARREAU Martin
##

CC = 		gcc
CFLAGS =	-Wall -Werror -Wextra -I./include -g2
LDFLAGS =	-L./libmy -lmy
NAME =		my_slack_clt
SRC =		my_memset.c \
		my_implode.c \
		my_explode.c \
		actions.c \
		cmd.c \
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
