#include "push_swap.h"

void	error_exit(void)
{
	printf("Error.\n");
	exit(1);
}

void	parse_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 2)
		error_exit();
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && (j != 0 && j != '-'))
				error_exit();
			j++;
		}
		i++;
	}
}