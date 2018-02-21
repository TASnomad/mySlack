/*
** client.c for MySlack in /home/nomad/mySlack/server
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sun Feb 18 22:17:49 2018 BARREAU Martin
** Last update Wed Feb 21 17:51:08 2018 BARREAU Martin
*/

#include	<client.h>
#include	<srv.h>
#include	<libmy.h>
#include	<stdlib.h>

t_client	*create_client(int sock, char *name, char *channel)
{
  t_client	*clt;

  (void) channel;
  clt = (t_client *) malloc(sizeof(t_client *));
  if (!clt)
    return (0x0);
  clt->channel = my_strdup(DEFAULT_CHAN);
  /*if (!channel)
    clt->channel = my_strdup(DEFAULT_CHAN);
  else
  clt->channel = my_strdup(channel);*/
  clt->fd = sock;
  clt->name = (name) ? my_strdup(name) : 0x0;
  clt->next = 0x0;
  clt->prev = 0x0;
  return (clt);
}

t_client	*find_client_by_sock(t_list *list, int sock)
{
  t_client	*first;
  t_client	*res;
  
  first = list->first;
  while (list->first->next && list->first->fd != sock)
    list->first = list->first->next;
  res = list->first;
  list->first = first;
  return (res);
}

int		is_login_taken(t_list *list, char *name)
{
  int		res;
  t_client	*base;
  
  base = list->first;
  res = 0;
  if (!list->first->next && !list->first->name)
    return (0);
  while (list->first)
    {
      if (list->first->name)
	if (my_strncmp(name, list->first->name, my_strlen(name)) == 0)
	  {
	    res = 1;
	    break;
	  }
      list->first = list->first->next;
    }
    list->first = base;
    return (res);
}

int		init_clients(t_list **list)
{
  if (!*list)
    *list = (t_list *) malloc(sizeof(t_list));
  (*list)->first = 0x0;
  (*list)->last = 0x0;
  (*list)->nb_elem = 0;
  return (1);
}

void		add_client(t_list *list, t_client *clt)
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
      clt->next = list->first;
      list->first = clt;
      list->nb_elem++;
    }
}

void		rmv_client(t_list *list, t_client *clt)
{
  t_client	*base;
  
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
      while (list->first != clt && list->first)
	list->first = list->first->next;
      if (list->first)
	{
	  if (!list->first->next)
	    list->last = 0x0;
	  else
	    {
	      list->first->next->prev = list->first->next;
	      list->first->prev->next = list->first->prev;
	      }
	}
    }
  list->first = base;
  list->nb_elem--;
}
