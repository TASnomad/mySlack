/*
** main.c for MySlack in /home/nomad/mySlack/server
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Feb 15 10:31:56 2018 BARREAU Martin
** Last update Thu Feb 15 10:33:29 2018 BARREAU Martin
*/

#include	<libmy.h>
#include 	<srv.h>
#include 	<unistd.h>
#include 	<stdlib.h>

#define		LEN(x, arr) while(arr[++x]);

int		main(int argc, char **argv)
{
  int 		sock;

  if (argc < 2)
    {
      my_putstr("Usage: ");
      my_putstr(*argv);
      my_putstr(" <PORT TO START SERVER>\n");
      return (-1);
    }
  sock = prepare_srv_socket(*(argv + 1));
  if (sock < 0)
    return (-1);
  my_putstr("[*] TCP server is running ...\n");
  main_server(sock);
  close(sock);
  return (0);
}
