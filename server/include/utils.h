/*
** utils.h for MySlack in /home/nomad/mySlack/server
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Wed Feb 21 09:47:46 2018 BARREAU Martin
** Last update Wed Feb 21 14:04:56 2018 BARREAU Martin
*/

#ifndef _UTILS_H_
#define _UTILS_H_

#define		LEN(x, arr) while(arr[++x]);

#define         PURGE(arr)      \
  int           __i;            \
  __i = 0;                      \
  while (*(arr + __i))          \
    {                           \
      free(*(arr + __i));	\
    }				\
  free(arr);

#include	<srv.h>

int		broadcast(t_client *, char *);

#endif /* ! _UTILS_H_ */
