#include	<libmy.h>
#include	<client.h>

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
