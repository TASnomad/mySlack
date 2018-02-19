/*
** cmd.c for MySlack in /home/nomad/mySlack/client
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sun Feb 18 22:36:53 2018 BARREAU Martin
** Last update Tue Feb 20 00:12:26 2018 BARREAU Martin
*/

#include	<cmd.h>
#include	<actions.h>
#include	<client.h>
#include	<utils.h>
#include	<libmy.h>
#include	<unistd.h>
#include	<stdlib.h>

#define		DISCARD(el) ((void) el)

t_action	cmds[] = {
  { INPUT_HELP_CMD, cmd_helper },
  { INPUT_LIST_CMD, req_list },
  { INPUT_PM_CMD, send_pm },
  { INPUT_QUIT_CMD, handle_quit },
  { 0x0, 0x0 }
};

int		handle_cmd(t_client *clt, char *raw)
{
  int		found;
  int		i;
  int		res;

  i = found = res = 0;
  while ((*(cmds + i)).name && !found)
    {
      if (!my_strncmp(raw, (*(cmds + i)).name, my_strlen((*(cmds + i)).name)))
	{
	  res = (*(cmds + i)).cmd(clt, raw);
	  found = 1;
	}
      i += 1;
    }
  if (!found)
    {
      send_msg(clt, raw);
      return (1);
    }
  return (res);
}

int		cmd_helper(t_client *clt, char *raw)
{
  DISCARD(clt);
  DISCARD(raw);
  my_putstr(YELLOW"Availables MySlack commands:\n"RESET);
  my_putstr(YELLOW"- '/quit': deconnect you from the server\n"RESET);
  my_putstr(YELLOW"- '/list': get all usernames connected to the server\n"RESET);
  my_putstr(YELLOW"- '/pm xxx yyyy': send personnally to xxx the yyy message\n"RESET);
  my_putstr(YELLOW"- '/help': will prompt those messages'\n"RESET);
  return (1);
}

int		send_pm(t_client *clt, char *raw)
{
  DISCARD(clt);
  DISCARD(raw);
  return (1);
}

int		req_list(t_client *clt, char *raw)
{
  char		*req;

  DISCARD(raw);
  req = my_strdup(LIST_CMD";");
  send(clt->fd, req, my_strlen(req), 0);
  free(req);
  return (1);
}

int		handle_quit(t_client *clt, char *raw)
{
  char		**cmd;
  char		*req;

  DISCARD(raw);
  if (!(cmd = (char **) malloc(2 * sizeof(char **))))
    return (0);
  *(cmd + 0) = my_strdup(QUIT_CMD);
  *(cmd + 1) = my_strdup(clt->name);
  req = my_implode(cmd, ';');
  send(clt->fd, req, my_strlen(req), 0);
  free(req);
  free(cmd);
  return (0);
}
