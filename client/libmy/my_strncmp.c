/*
** my_strncmp.c for my_strncmp in /home/nomad/C/J4/barrea_m/my_strncmp
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Oct 19 11:30:17 2017 BARREAU Martin
** Last update Fri Oct 20 18:36:14 2017 BARREAU Martin
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((s1[i] != 0 && (s2[i] != 0)) && (i < n))
    {
      if ((s1[i] != s2[i]) && (i < n))
	{
	  break;
	}
      i += 1;
    }
  if ((s1[i] > s2[i]) && (i < n))
    return (1);
  else if ((s1[i] < s2[i]) && (i < n))
    return (-1);
  else
    return (0);
}
