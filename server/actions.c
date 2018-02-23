/*
** actions.c for MySlack in /home/nomad/mySlack/server
**
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
**
** Started on  Sun Feb 18 22:20:27 2018 BARREAU Martin
** Last update Fri Feb 23 09:22:03 2018 BRIAND Corentin
*/

#include	<client.h>
#include	<utils.h>
#include	<srv.h>
#include	<libmy.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>


t_action	actions[] = {
  { CMD_LOGIN, handle_login },
  { CMD_LIST, handle_list },
  { CMD_QUIT, handle_quit },
  { CMD_MSG, handle_new_msg },
  { 0x0, 0x0 }
};

void		broadcast_to_channel(int sender, char *msg)
{
  t_client	*clt;
  t_client	*base;

  base = clients->first;
  clt = find_client_by_sock(clients, sender);
  if (!clt)
    return (my_putstr("Cannot retrieve !\n"));
  while (clients->first)
    {
      if (clients->first->fd != clt->fd)
	send(clients->first->fd, msg, my_strlen(msg), 0);
      clients->first = clients->first->next;
    }
  clients->first = base;
}

int		handle_quit(int sock, char *raw)
{
  char		**cmd;
  char		*res;
  t_client	*clt;

  (void) raw;
  clt = find_client_by_sock(clients, sock);
  if (!(cmd = (char **) malloc(2 * sizeof(char *))))
    return (0);
  *(cmd + 0) = my_strdup(CMD_QUIT);
  *(cmd + 1) = my_strdup(clt->name);
  res = my_implode(cmd, ';');
  broadcast_to_channel(sock, res);
  free(*(cmd + 0));
  free(*(cmd + 1));
  free(cmd);
  free(res);
  return (1);
}

int		handle_login(int sock, char *buff)
{
  char		**cmd;
  char		*response;
  int		res;
  int		i;
  t_client	*clt;

  i = 0;
  cmd = my_explode(buff, ';');
  res = is_login_taken(clients, cmd[1]);
  if (res == 0)
    {
      res = check_login(cmd[1]);
    }
  if (res)
      cmd[1] = my_strdup("KO");
  else
    {
      clt = find_client_by_sock(clients, sock);
      if (clt->name)
            free(clt->name);
      clt->name = my_strdup(cmd[1]);
      cmd[1] = my_strdup("OK");
    }
  response = my_strdup(my_implode(cmd, ';'));
  send(sock, response, my_strlen(response), 0);
  free(response);
  while (*(cmd + i))
    {
      free(*(cmd + i));
      i += 1;
    }
  free(cmd);
  return (!res);
}

int		handle_new_msg(int sock, char *raw)
{
  int		i;
  int		len;
  char		**cmd;

  PRINT_NBR("__Sock : ", sock);
  i = 0;
  len = 0;
  cmd = my_explode(my_strdup(raw), ';');
  while (cmd[++i]);
  broadcast_to_channel(sock, raw);
  while (i < len)
    {
      free(*(cmd + i));
      i += 1;
    }
  free(cmd);
  return (1);
}

int		handle_list(int sock, char *raw)
{
  char		**cmd;
  char		*builder;
  char		**names;
  char		*res;
  int		i;
  t_client	*base;

  (void) raw;
  i = 0;
  names = cmd = 0x0;
  builder = res = 0x0;
  if (!(names = (char **) malloc((clients->nb_elem + 1) * sizeof(char *))))
    return (0);
  if (!(cmd = (char **) malloc(2 * sizeof(char *))))
    return (0);
  base = clients->first;
  while (clients->first)
    {
      if (clients->first->name != NULL)
	{
	  *(names + i) = my_strdup(clients->first->name);
	}
      clients->first = clients->first->next;
      i++;
    }
  builder = my_implode(names, '/');
  clients->first = base;
  *(cmd + 0) = my_strdup(CMD_LIST);
  *(cmd + 1) = my_strdup(builder);
  res = my_strdup(my_implode(cmd, ';'));
  send(sock, res, my_strlen(res), 0);
  free(res);
  free(builder);
  free(cmd[0]);
  free(cmd[1]);
  free(cmd);
  i = 0;
  while (i < clients->nb_elem && *(names + i) != NULL)
    {
      free(*(names + i));
      i++;
    }
  free(names);
  return (1);
}

int		handle_incoming(int sock_clt, char *raw_buff, int raw_size)
{
  char		**cmd;
  char		*data;
  int		found;
  int		i;
  int		len;
  int		res;

  i = len = found = res = 0;
  cmd = 0x0;
  data = my_strdup(raw_buff);
  cmd = my_explode(data, ';');
  if (!cmd)
    return (0);
  while ((*(actions + i)).name && !found)
    {
      if (my_strcmp(cmd[0], (*(actions + i)).name) == 0)
        {
	  res = (*(actions + i)).cmd(sock_clt, data);
	  found = 1;
        }
      i += 1;
    }
  my_memset(raw_buff, 0x0, raw_size);
  free(cmd);
  return (res);
}
