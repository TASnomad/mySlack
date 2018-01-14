/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/nomad/C/J7/barrea_m/my_str_to_wordtab
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Sat Oct 21 19:23:08 2017 BARREAU Martin
** Last update Tue Oct 24 14:44:22 2017 BARREAU Martin
*/

#include	<stdlib.h>

char		*my_strncpy(char *dest, char *src, int n);

int		detect_wd(char c)
{
  if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)))
    return (1);
  else
    return (0);
}

int		detect_nb(char c)
{
  if ((c > 47) && (c < 58))
    return (1);
  else
    return (0);
}

int		nb_word(char c)
{
  if ((detect_wd(c) == 1) || (detect_nb(c) == 1))
    return (1);
  return (0);
}

int		count_word(char *str)
{
  int		cpt;
  int		nb;
  int		wd;
  int		nb_word;

  cpt = 0;
  nb_word = 0;
  while (str[cpt] != '\0')
    {
      nb = 0;
      wd = 0;
      while (detect_wd(str[cpt]) || detect_nb(str[cpt]))
	{
	  if (detect_wd(str[cpt]) == 1)
	    wd = 2;
	  else
	    nb = 1;
	  cpt = cpt + 1;
	}
      if (wd > 0 || nb > 0)
	nb_word = nb_word + 1;
      if (str[cpt] != '\0')
	cpt = cpt + 1;
    }
  return (nb_word);
}

char		**my_str_to_wordtab(char *str)
{
  int		cpt;
  int		cptr;
  int		len;
  char		**tab;

  cpt = cptr = len = 0;
  tab = malloc((count_word(str) + 1) * sizeof(char *));
  if (tab == 0)
    return (0);
  while (str[cpt] != '\0')
    {
      if (nb_word(str[cpt]) == 1)
	len = len + 1;
      if ((nb_word(str[cpt + 1]) == 0) && (nb_word(str[cpt]) == 1))
	{
	  tab[cptr] = malloc((len + 1) * sizeof(char));
	  tab[cptr] = my_strncpy(tab[cptr], str + cpt - len + 1, len);
	  tab[cptr][len] = '\0';
	  len = 0;
	  cptr = cptr + 1;
	}
      cpt = cpt + 1;
    }
  tab[count_word(str)] = 0;
  return (tab);
}
