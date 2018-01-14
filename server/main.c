#include <libmy.h>
#include <srv.h>
#include <unistd.h>
#include <stdlib.h>

#define	LEN(x, arr) while(arr[++x]);

int main(int argc, char **argv)
{
    int sock;
	int i;
	int len;
	char **test;

	if (argc < 2)
	{
		my_putstr("Usage: ");
		my_putstr(*argv);
		my_putstr(" <PORT TO START SERVER>\n");
		return (-1);
	}
	len = 0;
	test = my_explode("login;toto;pooop;troll;pouet", ';');
	LEN(len, test);
	i = 0;
	while (i < len)
	{
		my_putstr(*(test + i));
		my_putchar('\n');
		i++;
	}
	sock = prepare_srv_socket(*(argv + 1));
	if (sock < 0)
		return (-1);
	my_putstr("[*] TCP server is starting ...\n");
	main_server(sock, 42);
	close(sock);
	return (0);
}
