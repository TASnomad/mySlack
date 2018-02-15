#ifndef _CLIENT_H_
#define _CLIENT_H_

#include	<sys/select.h>

#define DEFAULT_CHAN    "general"

#define	CMD_LOGIN	"login"
#define	CMD_MSG		"msg"
#define	CMD_LIST	"list"
#define	CMD_QUIT	"quit"

#define	MAX_CLIENTS	FDSETSIZE

typedef	struct		s_action
{
	char		*name;
	int		(*cmd)();
}			t_action;

typedef struct		s_client
{
	int             fd;
	char            *name;
	char            *channel;
	struct s_client	*next;
	struct s_client	*prev;
}			t_client;

typedef struct		s_list
{
	t_client        *first;
	t_client        *last;
	int             nb_elem;
}			t_list;

t_list	*clients;

int			init_clients(t_list **);
void			add_client(t_list *, t_client *);
void			rmv_client(t_list *, t_client *);

t_client		*create_client(int, char *, char *);
t_client		*find_client_by_sock(t_list *, int);

int			handle_login();
int			handle_new_msg();
int			handle_list();
int			is_login_taken(t_list *, char *);

void			print_clients(t_list *);

int			handle_incoming(int, char *, int);

#endif /* ! _CLIENT_H_ */
