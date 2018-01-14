CC =	gcc
AR = 	ar
NAME = 	libmy.a
SRC = 	my_putchar.c	\
	my_isneg.c	\
	my_put_nbr.c	\
	my_swap.c	\
	my_putstr.c	\
	my_strlen.c	\
	my_getnbr.c	\
	my_strcpy.c	\
	my_strncpy.c	\
	my_strcmp.c	\
	my_strncmp.c	\
	my_strcat.c	\
	my_strncat.c	\
	my_strstr.c	\
	my_strdup.c	\
	my_str_to_wordtab.c
OBJS =	$(SRC:%.c=%.o)
RM =	rm -f
CFLAGS = -Wall -Werror

all:		$(OBJS) $(NAME)

$(NAME):		$(OBJS)
		$(AR) r $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: 	clean fclean all

%.o:%.c
		$(CC) $(CFLAGS) -c $<
