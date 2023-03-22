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
// 	// return (res);
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
// 	// return (res);
}

char	**ft_split(int ac, char **av)
{
	char	**res;
	char	*buff;
	char	*s;
	int		nb_word;

	s = parse_join(ac, av);
	if (parse_args(s) == 1)
		return (NULL);
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

// static int	count_words(const char *str)
// {
// 	int i;
// 	int trigger;

// 	i = 0;
// 	trigger = 0;
// 	while (*str)
// 	{
// 		if (!is_space(*str) && trigger == 0)
// 		{
// 			trigger = 1;
// 			i++;
// 		}
// 		else if (is_space(*str))
// 			trigger = 0;
// 		str++;
// 	}
// 	return (i);
// }

// static char	*word_dup(const char *str, int start, int finish)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	word = malloc((finish - start + 1) * sizeof(char));
// 	while (start < finish)
// 		word[i++] = str[start++];
// 	word[i] = '\0';
// 	return (word);
// }

// char		**ft_split(int ac, char **av)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		index;
// 	char	**split;
// 	char	*s;

// 	s = parse_join(ac, av);
// 	if (parse_args(s) == 1)
// 		return (NULL);
// 	if (!s || !(split = malloc((count_words(s) + 1) * sizeof(char *))))
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	index = -1;
// 	while (i <= ft_strlen(s))
// 	{
// 		if (!is_space(s[i]) && index < 0)
// 			index = i;
// 		else if ((is_space(s[i]) || i == ft_strlen(s)) && index >= 0)
// 		{
// 			split[j++] = word_dup(s, index, i);
// 			index = -1;
// 		}
// 		i++;
// 	}
// 	split[j] = 0;
// 	free(s);
// 	return (split);
// }