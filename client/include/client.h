/*
** client.h for MySlack in /home/nomad/mySlack/client/include
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sun Feb 18 22:37:16 2018 BARREAU Martin
** Last update Mon Feb 19 23:58:43 2018 BARREAU Martin
*/

#ifndef _CLIENT_H_
#define _CLIENT_H_

#include		<unistd.h>
#include		<arpa/inet.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<sys/select.h>
#include		<utils.h>

#define	EXPLODE_CHAR	';'

#define LOGIN_CMD       "login"
#define	RCV_MSG_CMD	"msg"
#define	LIST_CMD	"list"
#define	QUIT_CMD	"quit"

#define	CMD_INDEX	0
#define	LOGIN_INDEX	1
#define	CHANNEL_INDEX	2
#define	MSG_INDEX	3

#define	BUFSIZE		512

#define	CMD_PROMPT(login, chan)	\
  my_putstr(RED);		\
  my_putstr("my_slack # ");	\
  my_putstr(login);		\
  my_putchar('@');		\
  my_putstr(chan);		\
  my_putstr(" > ");		\
  my_putstr(RESET);

#define	INCOMING_PROMPT(login, chan) \
  my_putstr(CYAN);		     \
  my_putstr("my_slack # ");	     \
  my_putstr(login);		     \
  my_putchar('@');		     \
  my_putstr(chan);		     \
  my_putstr(" > ");		     \
  my_putstr(RESET);

typedef struct	s_client
{
  int		fd;
  char		*name;
  char		*channel;
}		t_client;

int		spawn_client(char *, char *);
t_client	*login_server(int);
void		main_client(t_client *);

#endif /* ! _CLIENT_H_ */
