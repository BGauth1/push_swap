/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:08:31 by gbertet           #+#    #+#             */
/*   Updated: 2023/03/29 15:08:33 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_empty_args(int ac, char **av)
{
	int	i;
	int	j;
	int	error;

	i = 1;
	while (i < ac)
	{
		j = 0;
		error = 1;
		if (av[i][0] == '\0')
			return (1);
		while (av[i][j] != '\0')
		{
			if (!is_space(av[i][j]))
				error = 0;
			j++;
		}
		if (error == 1)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (check_empty_args(ac, av))
		error_exit();
	stack_a = new_stack_a(ac - 1, av);
	stack_b = NULL;
	choose_sort(&stack_a, &stack_b);
	write_instruction(" ");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
