#include			<client.h>
#include			<utils.h>
#include			<actions.h>
#include			<libmy.h>
#include			<stdlib.h>
#include			<sys/socket.h>

t_action	my_actions[] = {
	{ RCV_MSG_CMD, recv_msg },
	{ 0x0, 0x0 }
};

int				handle_incoming(t_client *clt, char *raw)
{
	char			**cmd;
	int			found;
	int			i;
	int			res;

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
	char			**cmd;
	char			*req;

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

int				recv_msg(t_client *clt, char *msg)
{
	char			**cmd;

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
