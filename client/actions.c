/*
** actions.c for MySlack in /home/nomad/mySlack/client
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sun Feb 18 22:51:30 2018 BARREAU Martin
** Last update Tue Feb 20 00:04:44 2018 BARREAU Martin
*/

#include			<client.h>
#include			<utils.h>
#include			<actions.h>
#include			<libmy.h>
#include			<stdlib.h>
#include			<sys/socket.h>

t_action			my_actions[] = {
  { RCV_MSG_CMD, recv_msg },
  { LIST_CMD, recv_list },
  { QUIT_CMD, recv_quit },
  { 0x0, 0x0 }
};

int				recv_quit(t_client *clt, char *raw)
{
  char				**cmd;

  (void) clt;
  cmd = my_explode(raw, ';');
  my_putstr("\n[INFO]"GREEN);
  my_putstr(*(cmd + 1));
  my_putstr(" quit the server !\n"RESET);
  free(cmd);
  return (1);
}

int				handle_incoming(t_client *clt, char *raw)
{
  char				**cmd;
  int				found;
  int				i;
  int				res;
  
  i = found = res = 0;
  cmd = my_explode(raw, ';');
  if (!cmd)
    return (0);
  while ((*(my_actions + i)).name && !found)
    {
      if (my_strcmp(cmd[CMD_INDEX], (*(my_actions + i)).name) == 0)
	{
	  res = (*(my_actions +i)).cmd(clt, raw);
	  found = 1;
	}
      i += 1;
    }
  free(cmd);
  return (res);
}

int				send_msg(t_client *clt, char *raw)
{
  char				**cmd;
  char				*req;
  
  req = 0x0;
  cmd = (char **) malloc(4 * sizeof(char *));
  if (!cmd)
    return (-1);
  cmd[CMD_INDEX] = "msg";
  cmd[LOGIN_INDEX] = clt->name;
  cmd[CHANNEL_INDEX] = clt->channel;
  cmd[MSG_INDEX] = raw;
  req = my_implode(cmd, ';');
  return (send(clt->fd, req, my_strlen(req), 0));
}

int				recv_list(t_client *clt, char *msg)
{
  char				**cmd;
  char				**names;
  int				i;
  
  (void) clt;
  i = 0;
  cmd = my_explode(msg, EXPLODE_CHAR);
  names = my_explode(*(cmd + 1), '/');
  my_putstr(RED"Connected users:\n"RESET);
  while (*(names + i))
    {
      my_putstr(YELLOW"- ");
      my_putstr(*(names +i));
      my_putstr("\n"RESET);
      i += 1;
    }
  free(names);
  free(cmd);
  return (1);
}

int				recv_msg(t_client *clt, char *msg)
{
  char				**cmd;

  (void) clt;
  cmd = my_explode(msg, ';');
  if (!cmd)
    return (0);
  my_putchar('\n');
  INCOMING_PROMPT(cmd[LOGIN_INDEX], cmd[CHANNEL_INDEX]);
  write(1, cmd[MSG_INDEX], my_strlen(cmd[MSG_INDEX]));
  my_putchar('\n');
  free(cmd);
  return (1);
}
