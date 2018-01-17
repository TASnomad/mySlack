#ifndef _CLIENT_H_
#define _CLIENT_H_

#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/select.h>

#define LOGIN_CMD       "login"
#define MSG_SEND_CMD    "send_msg"
#define MSG_RECV_CMD    "recv_msg"
#define CHANNEL_CMD     "channel"

#define	BUFSIZE		512

#define	CMD_PROMPT(chan, login)	\
	my_putstr("my_slack # "); \
	my_putstr(login); \
	my_putchar('@'); \
	my_putstr(chan); \
	my_putstr(" > ");

typedef struct	s_client
{
	int	fd;
	char	*name;
	char	*channel;
}		t_client;

int		spawn_client(char *, char *);
int		send_msg(t_client *);
t_client	*login_server(int);
void		main_client(t_client *);

#endif /* ! _CLIENT_H_ */
