#include	<libmy.h>
#include	<client.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<sys/select.h>

#define PRINT_STR(prefix, variable, suffix) \
my_putstr(prefix); \
my_putstr(variable); \
my_putstr(suffix); \
my_putchar('\n');


int			spawn_client(char *ip, char *port)
{
	int					sock;
	struct sockaddr_in 	target;

	my_memset(&target, 0x0, sizeof(struct sockaddr_in));
	target.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &target.sin_addr.s_addr);
	target.sin_port = htons(my_getnbr(port));
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		return (-1);
	if (connect(sock, (struct sockaddr *) &target, sizeof(struct sockaddr_in)) < 0)
	{
		my_putstr("Can\'t connect to the give server !\n");
		close(sock);
		return (-1);
	}
	return (sock);
}

t_client		*login_server(int sock)
{
	int		count;
	char		buffer[BUFSIZE];
	char		**cmd;
	t_client	*c;

	count = 0;
	c = (t_client *) malloc(sizeof(t_client));
	cmd = (char **) malloc(2 * sizeof(char **));
	if (!cmd || !c)
		return (0x0);
	my_putstr("Votre login: ");
	while ((count = read(0, buffer, BUFSIZE)) < 2)
		my_putstr("Votre login: ");
	cmd[0] = LOGIN_CMD;
	cmd[1] = (char *) malloc(count - 1 * sizeof(char));
	my_strncpy(cmd[1], buffer, count - 1);
	c->name = (char *) malloc(count * sizeof(char));
	c->channel = (char *) malloc(my_strlen("general") * sizeof(char));
	my_memset(buffer, 0x0, 132);
	my_strcpy(buffer, my_implode(cmd, ';'));
	PRINT_STR("Login as: ", cmd[1], "\nPlease wait ...");
	send(sock, buffer, my_strlen(buffer), 0);
	my_memset(buffer, 0x0, 132);
	count = recv(sock, buffer, 132, 0);
	if (!my_strstr(buffer, "OK") || count < 1)
	{
		free(c);
		return (0x0);
	}
	c->fd = sock;
	my_strncpy(c->name, cmd[1], my_strlen(cmd[1]));
	c->channel = "general";
	free(cmd);
	return (c);
}

int		handle_incoming(t_client *clt, char *raw)
{
	(void) clt;
	(void) raw;
	return (0);
}

int		send_msg(t_client *clt, char *raw)
{
	char	**cmd;
	char	*req;

	req = 0x0;
	cmd = (char **) malloc(4 * sizeof(char *));
	if (!cmd)
		return (-1);
	cmd[0] = "msg";
	cmd[1] = clt->name;
	cmd[2] = clt->channel;
	cmd[3] = raw;
	req = my_implode(cmd, ';');
	return (send(clt->fd, req, my_strlen(req), 0));
}

int		rcv_msg(char *msg)
{
	char	**cmd;

	cmd = my_explode(msg, ';');
	if (!cmd)
		return (0);
	//CMD_PROMPT(cmd[2], cmd[1]);
	write(1, cmd[3], my_strlen(cmd[3]));
	my_putchar('\n');
	free(cmd);
	return (1);
}

void		main_client(t_client *clt)
{
	int s;
	int run;
	int readed;
	char msg[BUFSIZE];
	fd_set rfds;

	s = -1;
	run = 1;
	readed = 0;
	while (run)
	{
		FD_ZERO(&rfds);
		FD_SET(0, &rfds);
		FD_SET(clt->fd, &rfds);
		my_memset(msg, 0x0, BUFSIZE);
		CMD_PROMPT(clt->channel, clt->name);
		s = select(clt->fd + 1, &rfds, 0x0, 0x0, 0x0);
		if (s < 0)
			run = 0;
		if (FD_ISSET(0, &rfds))
		{
			readed = read(0, msg, BUFSIZE);
			if (readed < 0)
				run = 0;
			if (!my_strncmp("quit", msg, 4))
				run = 0;
			send_msg(clt, msg);
		}
		else if (FD_ISSET(clt->fd, &rfds))
		{
			readed = recv(clt->fd, msg, BUFSIZE, 0);
			if (!readed)
				run = 0;
			rcv_msg(msg);
		}
	}
	my_putstr("Déconnexion du serveur !!\n");
}
