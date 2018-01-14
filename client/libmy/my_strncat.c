/*
** my_strncat.c for my_strncat in /home/nomad/C/J4/barrea_m/my_strncat
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Oct 19 12:19:11 2017 BARREAU Martin
** Last update Sat Oct 21 12:42:52 2017 BARREAU Martin
*/

int	my_strlen(char *str);

char	*my_strncat(char *dest, char *src, int n)
{
  int	dlen;
  int	i;

  i = 0;
  dlen = my_strlen(dest);
  while ((i < n) && (*(src + i)))
    {
      *(dest + dlen + i) = *(src + i);
      i += 1;
    }
  *(dest + dlen + i) = 0x0;
  return (dest);
}
