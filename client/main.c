#include <libmy.h>
#include <client.h>
#include <unistd.h>

#define BUFFSIZE	1024

#define PRINT_STR(prefix, variable, suffix) \
	my_putstr(prefix); \
	my_putstr(variable); \
	my_putstr(suffix); \
	my_putchar('\n');

int 		main(int argc, char **argv)
{
	int		client;
	char	buffer[BUFFSIZE];

	if (argc < 3)
	{
		PRINT_STR("Usage: ", *argv, " <SERVER IP>, <PORT TO CONNECT>");
		return (-1);
	}
	client = spawn_client(*(argv + 1), *(argv + 2));
	if (client < 0)
	{
		PRINT_STR("Unable to connect: ", *argv, " exits now !");
		return (-1);
	}
	my_memset(buffer, 'a', 42);
	send(client, buffer, 42, 0);
	recv(client, buffer, BUFFSIZE, 0);
	write(1, buffer, BUFFSIZE);
	sleep(1);
	close(client);
	return (0);
}
