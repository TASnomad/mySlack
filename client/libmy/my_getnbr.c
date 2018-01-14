/*
** my_getnbr.c for my_getnbr in /home/nomad/C/J5-6/barrea_m/my_getnbr
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Fri Oct 20 09:14:18 2017 BARREAU Martin
** Last update Sat Oct 21 13:27:27 2017 BARREAU Martin
*/

int	my_getnbr(char *str)
{
  int	i;
  int	n;
  int	neg;

  i = 0;
  n = 0;
  neg = 1;
  while ((str[i] == '+') || (str[i] == '-'))
    {
      if (str[i] == '-')
	  neg = neg * -1;
      i += 1;
    }
  while ((str[i]) && ((str[i] >= 48) && (str[i] <= 57)))
    {
      n = (n * 10) + (str[i] - '0');
      i += 1;
    }
  return (n * neg);
}
