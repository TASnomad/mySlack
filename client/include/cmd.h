/*
** cmd.h for 	MySlack in /home/nomad/mySlack/client/include
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sun Feb 18 22:40:21 2018 BARREAU Martin
** Last update Sun Feb 18 23:11:10 2018 BARREAU Martin
*/

#ifndef	_CMD_H_
#define	_CMD_H_

#include		<client.h>

#define INPUT_HELP_CMD	"/help"	
#define	INPUT_LIST_CMD	"/list"
#define	INPUT_PM_CMD	"/pm"
#define	INPUT_QUIT_CMD	"/quit"

int			handle_cmd(t_client *, char *);
int			handle_quit();
int			cmd_helper();
int			req_list();
int			send_pm();

#endif /* ! _CMD_H_ */
