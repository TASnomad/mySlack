/*
** my_strcpy.c for my_strcpy in /home/nomad/C/J4/barrea_m/my_strcpy
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Oct 19 09:35:24 2017 BARREAU Martin
** Last update Tue Oct 24 12:30:21 2017 BARREAU Martin
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (*(src + i))
    {
      *(dest + i) = *(src + i);
      i += 1;
    }
  *(dest + i) = 0x0;
  return (dest);
}
