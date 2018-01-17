#include	<libmy.h>
#include	<client.h>
#include	<stdlib.h>

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

int		send_msg(t_client *clt)
{
	char	**cmd;
	(void) clt;
	(void) cmd;
	return (0);
}

void		main_client(t_client *clt)
{
	int	run;
	int	readed;
	char	msg[BUFSIZE];

	run = 1;
	readed = 0;
	while (run)
	{
		my_memset(msg, 0x0, BUFSIZE);
		CMD_PROMPT(clt->channel, clt->name);
		readed = read(1, msg, BUFSIZE);
		if (readed < 0)
			run = 0;
		if (my_strncmp("quit", msg, my_strlen("quit")) == 0)
			run = 0;
	}
	my_putstr("Bye bye !\n");
}
