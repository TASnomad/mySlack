/*
** my_strcmp.c for my_strcmp in /home/nomad/C/J4/barrea_m/my_strcmp
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Oct 19 11:07:07 2017 BARREAU Martin
** Last update Thu Oct 19 11:42:41 2017 BARREAU Martin
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (*s1 == *s2)
    {
      if (!(*s1))
	{
	  return (0);
	}
      s1 += 1;
      s2 += 1;
    }
  i = *s1 - *s2;
  if (i > 0)
    {
      return (1);
    }
  return (-1);
}
