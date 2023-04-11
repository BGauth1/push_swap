/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:08:31 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/11 15:46:43 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*buff;

	if (stack_b != NULL)
		return (0);
	i = 0;
	buff = stack_a;
	while (buff != NULL)
	{
		if (buff->num != i)
			return (0);
		i++;
		buff = buff->next;
	}
	return (1);
}

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

	if (ac == 1)
		return (0);
	if (check_empty_args(ac, av))
		error_exit();
	stack_a = new_stack_a(ac - 1, av);
	stack_b = NULL;
	if (!check_sorted(stack_a, stack_b))
		choose_sort(&stack_a, &stack_b);
	write_instruction(" ");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
