/*
** my_putchar.c for my_putchar in /home/nomad/C/barrea_m/my_putchar
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Mon Oct 16 09:31:14 2017 BARREAU Martin
** Last update Mon Oct 16 09:58:41 2017 BARREAU Martin
*/

#include	<unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
