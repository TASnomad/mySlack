/*
** main.c for MySlack in /home/nomad/mySlack/client
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Feb 15 10:31:05 2018 BARREAU Martin
** Last update Thu Feb 15 10:31:16 2018 BARREAU Martin
*/

#include	<libmy.h>
#include	<utils.h>
#include	<client.h>
#include	<unistd.h>
#include	<stdlib.h>

#define PRINT_STR(prefix, variable, suffix) \
	my_putstr(prefix); \
	my_putstr(variable); \
	my_putstr(suffix); \
	my_putchar('\n');

int 		main(int argc, char **argv)
{
	int		client;
	t_client	*clt;

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
	clt = login_server(client);
	if (!clt)
	{
		my_putstr("Login process, abort now !\n");
		return (-1);
	}
	my_putstr(CLEAR);
	PRINT_STR(YELLOW, "Connected to the server !\n", RESET);
	main_client(clt);
	close(clt->fd);
	free(clt);
	return (0);
}
