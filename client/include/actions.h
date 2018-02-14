#ifndef	_ACTIONS_H_
#define	_ACTIONS_H_

#include	<client.h>

typedef struct	s_action
{
	char	*name;
	int	(*cmd)();
}		t_action;

int		handle_incoming(t_client *, char *);
int		send_msg(t_client *, char *);
int		recv_msg(t_client *, char *);

#endif /* ! _ACTIONS_H_ */
