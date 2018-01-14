/*
** my_putstr.c for my_putstr in /home/nomad/C/J3/barrea_m/my_putstr
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Wed Oct 18 09:07:45 2017 BARREAU Martin
** Last update Wed Oct 18 09:09:01 2017 BARREAU Martin
*/

void	my_putchar(char c);

void	my_putstr(char *str)
{
  while ((*str))
    {
      my_putchar(*str);
      str += 1;
    }
}
