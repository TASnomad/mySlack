/*
** my_swap.c for my_swap in /home/nomad/C/J3/barrea_m/my_swap
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Wed Oct 18 09:20:22 2017 BARREAU Martin
** Last update Wed Oct 18 09:34:21 2017 BARREAU Martin
*/

void	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
