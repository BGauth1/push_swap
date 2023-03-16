#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	change_instruction(char *str1, char *str2)
{
	int	i;

	if (str1[0] != str2[0] || str1[0] == 'p' || str2[0] == 'p')
		return (0);
	i = 1;
	while (str1[i] == str2[i])
		i++;
	if (ft_abs(str1[i] - str2[i]) == 1)
	{
		str1[i] = str1[i - 1];
		return (1);
	}
	return (0);
}

void	write_instruction(char *instruction)
{
	static char	*str;

	if (instruction[0] == ' ')
	{
		if (str)
		{
			write(1, str, ft_strlen(str));
			free(str);
		}
		return ;
	}
	if (!str)
	{
		str = malloc(5 * sizeof(char));
		if (!str)
			return ;
		ft_strlcpy(str, instruction, 5);
		return ;
	}
	if (!change_instruction(str, instruction))
	{
		write(1, str, ft_strlen(str));
		ft_strlcpy(str, instruction, 5);
	}
}
