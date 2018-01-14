#include <client.h>
#include <libmy.h>
#include <stdlib.h>

t_client        *create_client(int sock, char *name, char *channel)
{
    t_client    *clt;

    clt = (t_client *) malloc(sizeof(t_client *));
    if (!clt)
        return (0x0);
    if (!channel)
        channel = my_strdup(DEFAULT_CHAN);
    clt->fd = sock;
    clt->name = name;
    clt->channel = channel;
    return (clt);
}

t_client        *find_client_by_sock(t_list *list, int sock)
{
    t_client    *first;
    t_client    *res;

    first = list->first;
    while (list->first->next && list->first->fd != sock)
        list->first = list->first->next;
    res = list->first;
    list->first = first;
    return (res);
}

int             init_clients(t_list *list)
{
    if (!list)
        list = (t_list *) malloc(sizeof(t_list));
    my_memset(list, 0x0, sizeof(t_list));
    if (!list)
        return (0);
    list->first = 0x0;
    list->last = 0x0;
    list->nb_elem = 0;
    return (1);
}

void            add_client(t_list *list, t_client *clt)
{
    if (!list->first)
    {
        list->first = clt;
        list->last = 0x0;
        list->nb_elem++;
    }
    else
    {
        list->first->prev = clt;
        clt->prev = list->first;
        list->first = clt;
        list->nb_elem++;
    }
}

void            rmv_client(t_list *list, t_client *clt)
{
    t_client *base;

    base = list->first;
    if (list->nb_elem == 1 && list->first == clt)
    {
        list->first = 0x0;
        list->last = 0x0;
        base = 0x0;
    }
    else if (list->first == clt)
    {
        base = base->next;
        base->prev = 0x0; 
    }
    else
    {
        while (list->first != clt && list->first->next)
        {
            list->first = list->first->next;
            if (list->first)
            {
                if (list->first->next)
                    list->last = 0x0;
                else
                {
                    list->first->next->prev = list->first->next;
                    list->first->prev->next = list->first->prev;
                }
            }
        }
    }
    free(clt);
    list->first = base;
    list->nb_elem--;
}