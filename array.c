#include "push_swap.h"

int	*fill_tab(int *ac, char **av)
{
	int	i;
	int	*tab;
	char	**args;

	i = 0;
	args = ft_split(*ac, av);
	if (!args)
		error_exit();
	while (args[i] != NULL)
		i++;
	*ac = i;
	tab = malloc(i * sizeof(int));
	if (!tab)
	{
		ft_free_split(args);
		error_exit();
	}
	i = 0;
	while (args[i] != NULL)
	{
		tab[i] = ft_atoi(args[i]);
		i++;
	}
	ft_free_split(args);
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