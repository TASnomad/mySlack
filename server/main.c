#include <libmy.h>
#include <srv.h>
#include <unistd.h>
#include <stdlib.h>

#define	LEN(x, arr) while(arr[++x]);

int main(int argc, char **argv)
{
	int sock;
	char **test;
	char *test2;

	if (argc < 2)
	{
		my_putstr("Usage: ");
		my_putstr(*argv);
		my_putstr(" <PORT TO START SERVER>\n");
		return (-1);
	}

	test = my_explode("login;toto;poop;troll;pouet", ';');
	test2 = my_implode(test, ';');
	my_putstr(test2);
	my_putchar('\n');
	sock = prepare_srv_socket(*(argv + 1));
	if (sock < 0)
		return (-1);
	my_putstr("[*] TCP server is starting ...\n");
	main_server(sock, 42);
	close(sock);
	return (0);
}
