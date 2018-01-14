/*
** my_strstr.c for my_strstr in /home/nomad/C/J4/barrea_m/my_strstr
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Oct 19 13:50:28 2017 BARREAU Martin
** Last update Tue Oct 24 11:32:59 2017 BARREAU Martin
*/

int	my_strlen(char *str);

char	*my_strstr(char *str, char *to_find)
{
  int	size;
  int	c;
  char	*save;

  c = 0;
  save = to_find;
  size = my_strlen(to_find);
  if (!*to_find)
    return (str);
  while (*str != 0)
    {
      while ((*str == *to_find) && *to_find != 0)
	{
	  ++c;
	  if (c == size)
	    return (str - c + 1);
	  ++str;
	  ++to_find;
	}
      ++str;
      to_find = save;
      c = 0;
    }
  return (0);
}
