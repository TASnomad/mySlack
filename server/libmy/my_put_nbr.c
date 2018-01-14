/*
** my_put_nbr.c for my_put_nbr in /home/nomad/C/J5-6/barrea_m/my_put_nbr
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Fri Oct 20 09:03:50 2017 BARREAU Martin
** Last update Tue Oct 24 11:03:23 2017 BARREAU Martin
*/

void	my_putchar(char c);

void	my_underflow(unsigned int n)
{
  if (n > 9)
    {
      my_underflow(n / 10);
    }
  my_putchar((n % 10) + '0');
}

void	my_put_nbr(int n)
{
  if (n == -2147483648)
    {
      my_putchar('-');
      return (my_underflow(n));
    }
  if (n < 0)
    {
      my_putchar('-');
      n = n * -1;
    }
  if (n > 9)
    {
      my_put_nbr(n / 10);
    }
  my_putchar((n % 10) + '0');
}
