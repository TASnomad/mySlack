#ifndef _CLIENT_H_
#define _CLIENT_H_

#define DEFAULT_CHAN    "general"

typedef	struct	    s_action
{
	char		    *name;
	int			    (*cmd)();
}				    t_action;

typedef struct 	    s_client
{
	int             fd;
	char            *name;
    char            *channel;
    struct s_client *next;
    struct s_client *prev;
}				    t_client;

typedef struct      s_list
{
    t_client        *first;
    t_client        *last;
    int             nb_elem;
}                   t_list;

int         init_clients(t_list *);
void        add_client(t_list *, t_client *);
void        rmv_client(t_list *, t_client *);

t_client    *create_client(int, char *, char *);
t_client    *find_client_by_sock(t_list *, int);

#endif /* ! _CLIENT_H_ */