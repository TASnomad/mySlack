/*
** my_strdup.c for my_strdup in /home/nomad/C/J7/barrea_m/my_strdup
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sat Oct 21 15:42:01 2017 BARREAU Martin
** Last update Tue Oct 24 12:23:30 2017 BARREAU Martin
*/

#include	<stdlib.h>

int		my_strlen(char *str);
char		*my_strcpy(char *dest, char *src);

char		*my_strdup(char *str)
{
  char		*tmp;
  int		len;

  len = my_strlen(str);
  tmp = (char *) malloc(len);
  my_strcpy(tmp, str);
  return (tmp);
}
