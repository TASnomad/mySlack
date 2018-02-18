/*
** my_explode.c for MySlack in /home/nomad/mySlack/client
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sun Feb 18 22:34:57 2018 BARREAU Martin
** Last update Sun Feb 18 22:35:32 2018 BARREAU Martin
*/

#include	<libmy.h>
#include	<stdlib.h>

char		**my_explode(char *str, char del)
{
  int		len;
  int		i;
  int		j;
  int		k;
  char 		tmp;
  char		**res;
  
  i = j = k = 0;
  len = my_strlen(str);
  tmp = 0x0;
  res = 0x0;
  res = (char **) realloc(res, sizeof(char **));
  res[0] = (char *) malloc(len * sizeof(char));
  while (i < len + 1)
    {
      tmp = str[i++];
      if (tmp == del || tmp == 0x0)
	{
	  res[j][k] = 0x0;
	  res[j] = (char *) realloc(res[j], k * sizeof(char));
	  k = 0;
	  res = (char **) realloc(res, (++j + 1) * sizeof(char **));
	  res[j] = (char *) malloc(len * sizeof(char));
	}
      else
	res[j][k++] = tmp;
    }
  res[j] = 0x0;
  return (res);
}
