/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:17:43 by gbertet           #+#    #+#             */
/*   Updated: 2023/03/29 15:17:44 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static int	change_instruction(char *s1, char *s2)
{
	int	i;

	if (s1[0] != s2[0] || s1[0] == 'p' || s2[0] == 'p'
		|| ft_strlen(s1) != ft_strlen(s2))
		return (0);
	i = 1;
	while (s1[i])
		i++;
	if (ft_abs(s1[i] - s2[i]) == 1)
	{
		s1[i] = s1[i - 1];
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
