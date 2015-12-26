/*
** my_getnbr.c for é'-è_ç in /home/galpin_a/rendu/Library/lib/my
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Nov 10 14:00:14 2015 Antoine Galpin
** Last update Thu Dec 24 00:03:50 2015 Galpin
*/

int	my_getnbr(const char *str)
{
  int	pos;
  int	signe;
  int	nbr;

  signe = 1;
  pos = 0;
  while (str[pos] != '\0' && (str[pos] == '+' || str[pos] == '-'))
    {
      if (str[pos] == '-')
	{
	  signe = signe * - 1;
	}
      pos = pos + 1;
    }
  str = str + pos;
  nbr = 0;
  pos = 0;
  while (str[pos] >= '0' && str[pos] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr - (str[pos] - '0');
      pos = pos + 1;
    }
  return (nbr * signe * - 1);
}
