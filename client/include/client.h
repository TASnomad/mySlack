#ifndef _CLIENT_H_
#define _CLIENT_H_

#include		<unistd.h>
#include		<arpa/inet.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<sys/select.h>

#include		<utils.h>

#define LOGIN_CMD       "login"
#define	RCV_MSG_CMD	"msg"

#define	CMD_INDEX	0
#define	LOGIN_INDEX	1
#define	CHANNEL_INDEX	2
#define	MSG_INDEX	3


#define	BUFSIZE		512


#define	CMD_PROMPT(login, chan) \
my_putstr(RED); \
	my_putstr("my_slack # "); \
	my_putstr(login); \
	my_putchar('@'); \
	my_putstr(chan); \
	my_putstr(" > "); \
	my_putstr(RESET);

#define	INCOMING_PROMPT(login, chan) \
	my_putstr(CYAN); \
	my_putstr("my_slack # "); \
	my_putstr(login); \
	my_putchar('@'); \
	my_putstr(chan); \
	my_putstr(" > "); \
	my_putstr(RESET);

typedef struct	s_client
{
	int	fd;
	char	*name;
	char	*channel;
}		t_client;

int		spawn_client(char *, char *);
//int		send_msg(t_client *, char *);
t_client	*login_server(int);
void		main_client(t_client *);

#endif /* ! _CLIENT_H_ */
