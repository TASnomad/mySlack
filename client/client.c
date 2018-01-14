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

char		*login_server(int sock)
{
	int		count;
	char	*buffer;
	char	**cmd;

	count = 0;
	cmd = (char **) malloc(2 * sizeof(char **));
	buffer = (char *) malloc(512 * sizeof(char));
	if (!buffer || !cmd)
		return (0x0);
	my_putstr("Votre login: ");
	while ((count = read(0, buffer, 512)) < 1)
		my_putstr("Votre login: ");
	cmd[0] = my_strdup(LOGIN_CMD);
	cmd[1] = (char *) malloc(count * sizeof(char));
	my_strncpy(cmd[1], buffer, count);
	my_memset(buffer, 0x0, 512);
	buffer = my_implode(cmd, ';');
	my_putstr(buffer);
	PRINT_STR("Login as: ", cmd[1], "\nPlease wait ...");
	send(sock, buffer, my_strlen(buffer), 0);
	my_memset(buffer, 0x0, 512);
	count = recv(sock, buffer, 512, 0);
	PRINT_STR("Data received from server: ", buffer, "\n");
	return (cmd[1]);
}

void		main_client(int sock)
{
	(void) sock;
}