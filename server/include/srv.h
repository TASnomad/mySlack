/*
** srv.h for MySlack in /home/nomad/mySlack/server/include
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sun Feb 18 22:26:12 2018 BARREAU Martin
** Last update Sun Feb 18 22:26:38 2018 BARREAU Martin
*/

#ifndef _SRV_H_
#define _SRV_H_

#define	DISCARD(el) (void)el

#define	PRINT_STR(prefix, variable) \
  my_putstr(prefix);		    \
  my_putstr(variable);		    \
  my_putchar('\n');

#define PRINT_NBR(prefix, variable) \
  my_putstr(prefix);		    \
  my_put_nbr(variable);		    \
  my_putchar('\n');

int	prepare_srv_socket(char *);
void	main_server(int);
int	read_socket_data(int, char *);

#endif /* _SRV_H_ */
