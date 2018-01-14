/*
** my_strncpy.c for my_strncpy in /home/nomad/C/J4/barrea_m/my_strncpy
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Oct 19 09:40:18 2017 BARREAU Martin
** Last update Thu Oct 19 16:39:03 2017 BARREAU Martin
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while ((i < n) && (*(src + i)))
    {
      *(dest + i) = *(src + i);
      i += 1;
    }
  while (i < n)
    {
      *(dest + i) = 0x0;
      i += 1;
    }
  return (dest);
}
