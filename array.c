/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:02:03 by gbertet           #+#    #+#             */
/*   Updated: 2023/03/29 15:02:10 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_duplicates(int *tab, int length)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*atoi_args(char **args, int *tab)
{
	int			i;
	long long	num;

	i = 0;
	while (args[i] != NULL)
	{
		num = ft_atoi(args[i]);
		if (num > 2147483647 || num < -2147483648)
			return (NULL);
		tab[i] = ft_atoi(args[i]);
		i++;
	}
	if (parse_duplicates(tab, i) == 1)
		return (NULL);
	return (tab);
}

int	*fill_tab(int *ac, char **av)
{
	int		i;
	int		*tab;
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
	if (atoi_args(args, tab) == NULL)
	{
		ft_free_split(args);
		free(tab);
		error_exit();
	}
	ft_free_split(args);
	return (tab);
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
