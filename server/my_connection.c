#include				<unistd.h>
#include				<arpa/inet.h>
#include				<sys/types.h>
#include				<sys/socket.h>
#include				<sys/select.h>
#include				<libmy.h>
#include				<stdlib.h>
#include				<srv.h>
#include				<client.h>

t_list	*clients;

int						prepare_srv_socket(char *port)
{
	int					srv_socket;
	int					opts;
	struct sockaddr_in	srv;

	srv_socket = -1;
	opts = 1;
	my_memset(&srv, 0, sizeof(struct sockaddr_in));
	srv.sin_family = AF_INET;
	srv.sin_addr.s_addr = INADDR_ANY;
	srv.sin_port = htons(my_getnbr(port));
	srv_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (srv_socket < 0)
		return (-1);
	if (setsockopt(srv_socket, SOL_SOCKET, SO_REUSEADDR, &opts, sizeof(int)) < 0)
		my_putstr("TCP server can\'t run with SO_REUSEADDR flag!\n");
	if (bind(srv_socket, (struct sockaddr *) &srv, sizeof(srv)) < 0)
	{
		my_putstr("Can\'t bind network interface\nAbort now !\n");
		close(srv_socket);
		return (-1);
	}
	return (srv_socket);
}

int 					read_socket_data(int sock, char *buffer)
{
	return (recv(sock, buffer, 1024, 0));
}

void 					main_server(int srv, int max_listen)
{
	fd_set actives;
	fd_set readfds;
	int new_clt;
	int j;
	int len, rcv;
	char buffer[1024];
	struct sockaddr_in	client;

	init_clients(clients);
	my_memset((void *) &client, 0x0, sizeof(client));
	//clients = (int *) calloc(FD_SETSIZE, sizeof(int));
	len = sizeof(socklen_t);
	if (listen(srv, max_listen) < 0)
		return (my_putstr("Server can\'t listen on selected port !\nAbort now !\n"));
	FD_ZERO(&actives);
	FD_SET(srv, &actives);
	while (1)
	{
		readfds = actives;
		my_memset((void *) buffer, 0x0, 1024);
		my_memset((void *) &client, 0x0, sizeof(client));
		if (select(FD_SETSIZE, &readfds, 0x0, 0x0, 0x0) < 0)
			return (my_putstr("Noooo, select call is fucked up !\n"));
		for (j = 0; j < FD_SETSIZE; ++j)
		{
			if (FD_ISSET(j, &readfds))
			{
				if (j == srv)
				{
					new_clt = accept(srv, (struct sockaddr *) &client, (socklen_t *) &len);
					if (new_clt < 0)
						return (my_putstr("Server is full !\n"));
					PRINT_STR("Client: ", inet_ntoa(client.sin_addr))
					FD_SET(new_clt, &actives);
				}
				else
				{
					rcv = read_socket_data(j, buffer);
					my_put_nbr(rcv);
					if (rcv <= 0)
					{
						PRINT_NBR("Closing socket: ", j)
						close(j);
						FD_CLR(j, &actives);
					}
					else
					{
						PRINT_STR("Data received: ", buffer)
						send(j, buffer, rcv, 0);
					}
				}
			}
		}
	}
	close(srv);
}
