# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include "gnl.h"

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      printf("%s\n", tab[i]);
      i++;
    }
}

int	check_in(char *s1, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (strcmp(s1, tab[i]) == 0)
	return (-1);
      i++;
    }
  return (0);
}

char	**my_tri(char **buffer)
{
  int	i;
  int	k;
  char	**fin;

  if ((fin = malloc(sizeof(char*) * 20000 )) == NULL)
    return (NULL);
  i = 0;
  k = 0;
  while (buffer[i] != NULL)
    {
      if (check_in(buffer[i], fin) == 0)
	{
	  fin[k] = strdup(buffer[i]);
	  k++;
	}
      i++;
    }
  fin[k] = NULL;
  return (fin);
}

int	main(int ac, char **av)
{
  int	i;
  int	fd;
  char	**buffer;

  if ((buffer = malloc(sizeof(char *) * 20000)) == NULL)
    return (-1);
  if (ac != 2)
    return (-2);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (-3);
  i = 0;
  while ((buffer[i] = get_next_line(fd)) != NULL)
    i++;
  if ((buffer = my_tri(buffer)) == NULL)
    return (-4);
  print_tab(buffer);
  free(buffer);
  return 0;
}
