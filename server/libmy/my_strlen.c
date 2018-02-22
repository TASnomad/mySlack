/*
** my_strlen.c for my_strlen in /home/nomad/C/J3/barrea_m
**
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
**
** Started on  Wed Oct 18 09:02:53 2017 BARREAU Martin
** Last update Thu Feb 22 20:18:24 2018 BRIAND Corentin
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      ++i;
    }
  return (i);
}
