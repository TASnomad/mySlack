/*
** my_memset.c for MySlack in /home/nomad/mySlack/server
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sun Feb 18 22:16:23 2018 BARREAU Martin
** Last update Sun Feb 18 22:17:32 2018 BARREAU Martin
*/

#include	<libmy.h>

void		*my_memset(void *s, int c, int n)
{
  char		*dst;
  dst = 0x0;
  if (n)
    {
      dst = (char *) s;
      while (--n)
	{
	  *dst++ = c;
	}
    }
  return ((void *) dst);
}
