/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:10:26 by gbertet           #+#    #+#             */
/*   Updated: 2023/03/29 15:10:27 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	nb_words(char *s)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (is_space(s[i]))
			i++;
		else if ((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-')
		{
			n++;
			i++;
			if ((s[i - 1] == '+' || s[i - 1] == '-')
				&& (s[i] < '0' || s[i] > '9'))
				return (-1);
			while ((s[i] >= '0' && s[i] <= '9'))
				i++;
			if (!is_space(s[i]) && (s[i] < '0' || s[i] > '9'))
				return (-1);
		}
		else
			return (-1);
	}
	return (n);
}

int	parse_args(char *s)
{
	int	nb_word;

	nb_word = nb_words(s);
	if (nb_word == -1 || nb_word == 0)
		return (1);
	return (0);
}

char	*parse_join(int ac, char **av)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 1;
	str = ft_strjoin(" ", " ");
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (i < ac + 1)
	{
		tmp = ft_strjoin(str, av[i]);
		free(str);
		if (!tmp)
			return (NULL);
		str = ft_strdup(tmp);
		free(tmp);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}
