/*
** my_explode.c for MySlack in /home/nomad/mySlack/server
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Wed Feb 21 09:25:52 2018 BARREAU Martin
** Last update Wed Feb 21 18:07:34 2018 BARREAU Martin
*/

#include	<libmy.h>
#include	<stdlib.h>
#include	<string.h>

#define	LEN(x, arr) while(arr[++x]);

char		*my_implode(char **arr, char del)
{
  int		arr_cont;
  int		len;
  int		i;
  char		*res;
  
  i = len = arr_cont = 0;
  res = 0x0;
  LEN(arr_cont, arr);
  if (!arr)
    return (0x0);
  while (i < arr_cont)
    {
      len += my_strlen(arr[i]);
      i++;
    }
  res = (char *) malloc((len + 1 + arr_cont + 1) * sizeof(char));
  if (!res)
    return (0x0);
  i = 0;
  while (i < arr_cont)
    {
      my_strncat(res, arr[i], my_strlen(arr[i]));
      my_strncat(res, &del, 1);
      i++;
    }
  res[len + arr_cont - 1] = 0x0;
  return (res);
}

int             my_occurences(char *raw, char del)
{
  int           i;

  i = 0;
  while (*(raw))
    {
      if (*raw == del)
	i += 1;
      raw += 1;
    }
  return (i);
}

char            **my_explode(char *raw, char del)
{
  char          **cmd;
  int           i;
  int           count;

  i = 1;
  count = my_occurences(raw, del) + 1;
  if (! (cmd = (char **) malloc((count + 1) * sizeof(char *))))
    return (0x0);
  *(cmd + 0) = strtok(my_strdup(raw), &del);

  while (i < count)
    {
      *(cmd + i) = strtok(0x0, &del);
      i += 1;
    }
  return (cmd);
}
