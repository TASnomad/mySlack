/*
** my_strcat.c for my_strcat in /home/nomad/C/J4/barrea_m/my_strcat
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Oct 19 13:12:57 2017 BARREAU Martin
** Last update Sat Oct 21 12:40:18 2017 BARREAU Martin
*/

int	my_strlen(char *str);

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while (*(src + j))
    {
      *(dest + i + j) = *(src + j);
      j += 1;
    }
  *(dest + i + j) = 0x0;
  return (dest);
}
