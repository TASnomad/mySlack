/*
** actions.h for MySlack in /home/nomad/mySlack/client/include
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sun Feb 18 22:39:00 2018 BARREAU Martin
** Last update Fri Feb 23 09:18:29 2018 BARREAU Martin
*/

#ifndef	_ACTIONS_H_
#define	_ACTIONS_H_

#include	<client.h>

typedef struct	s_action
{
  char		*name;
  int		(*cmd)();
}		t_action;

int		handle_incoming(t_client *, char *);
int		recv_welcome(t_client *, char *);
int		send_msg(t_client *, char *);
int		recv_list(t_client *, char *);
int		recv_msg(t_client *, char *);
int		recv_quit(t_client *, char *);

#endif /* ! _ACTIONS_H_ */
