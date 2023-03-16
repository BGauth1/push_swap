#include "push_swap.h"

int	*fill_tab(int ac, char **av)
{
	int	i;
	int	*tab;

	i = 1;
	tab = malloc((ac - 1) * sizeof(int));
	if (!tab)
		error_exit();
	while (i < ac)
	{
		tab[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (tab);
}

int	parse_duplicates(int *tab, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	num_position(int *tab, int num, int length)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < length)
	{
		if (num > tab[i])
			pos++;
		i++;
	}
	return (pos);
}