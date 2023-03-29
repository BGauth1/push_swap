/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:05:14 by gbertet           #+#    #+#             */
/*   Updated: 2023/03/29 15:05:16 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_nb_word(const char *s)
{
	int	nb_word;
	int	i;

	nb_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!is_space(s[i]) && (is_space(s[i + 1]) || s[i + 1] == '\0'))
			nb_word++;
		i++;
	}
	return (nb_word);
}

static int	ft_word_size(const char *s)
{
	int	i;

	i = 0;
	while (!is_space(s[i]) && s[i] != '\0')
		i++;
	return (i);
}

static void	ft_malloc_words(char **res, char *buff, int nb_word)
{
	int	i;
	int	word_size;

	i = 0;
	while (nb_word != i)
	{
		while (is_space(*buff) || *buff == '\0')
			buff++;
		word_size = ft_word_size(buff);
		buff += word_size;
		res[i] = malloc((word_size + 1) * sizeof(char));
		if (!res[i])
		{
			i = 0;
			while (res[i] != NULL)
			{
				free(res[i]);
				i++;
			}
			return ;
		}
		i++;
	}
}

static void	ft_tostr(char **res, char *buff, int nb_word)
{
	int	i;
	int	j;
	int	word_size;

	i = 0;
	while (nb_word != i)
	{
		j = 0;
		while (is_space(*buff) || *buff == '\0')
			buff++;
		word_size = ft_word_size(buff);
		while (j < word_size)
		{
			res[i][j] = *buff;
			j++;
			buff++;
		}
		res[i][j] = '\0';
		if (!res[i])
			return ;
		i++;
	}
}

char	**ft_split(int ac, char **av)
{
	char	**res;
	char	*buff;
	char	*s;
	int		nb_word;

	s = parse_join(ac, av);
	if (parse_args(s) == 1)
	{
		free(s);
		return (NULL);
	}
	if (!s)
		return (NULL);
	buff = s;
	nb_word = ft_nb_word(s);
	res = malloc((nb_word + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[nb_word] = NULL;
	ft_malloc_words(res, buff, nb_word);
	if (!res)
		return (NULL);
	ft_tostr(res, buff, nb_word);
	free(s);
	return (res);
}
