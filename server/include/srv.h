#ifndef _SRV_H_
#define _SRV_H_

#define DISCARD(el) (void)el

#define PRINT_STR(prefix, variable) \
	my_putstr(prefix); \
	my_putstr(variable); \
	my_putchar('\n');

#define PRINT_NBR(prefix, variable) \
	my_putstr(prefix); \
	my_put_nbr(variable); \
	my_putchar('\n');

int		prepare_srv_socket(char *);
void 	main_server(int, int);
int 	read_socket_data(int, char *);

typedef	struct	s_action
{
	char		*name;
	int			(*cmd)();
}				t_action;

typedef struct 	s_client
{
	int fd;
	char *name;
	char *channel;
}				t_client;

#endif /* _SRV_H_ */
