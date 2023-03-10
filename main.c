#include "push_swap.h"

void	error_exit(void)
{
	printf("Error.\n");
	exit(1);
}

void	parse_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 2)
		error_exit();
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && (j != 0 && j != '-'))
				error_exit();
			j++;
		}
		i++;
	}
}

int	ft_atoi(const char *s)
{
	int	result;
	int	neg;
	int	i;

	result = 0;
	neg = 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + s[i] - '0';
		i++;
	}
	result *= neg;
	return (result);
}

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

t_stack	*new_stack_a(int *tab, int length)
{
	int		i;
	t_stack	*stack;

	stack = new_stack(num_position(tab, tab[0], length));
	if (!stack)
		return (NULL);
	i = 1;
	while (i < length)
	{
		ft_stackadd_back(&stack, new_stack(num_position(tab, tab[i], length)));
		i++;
	}
	return (stack);
}

int	main(int ac, char **av)
{
	int		*tab;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tmp;

	if (ac < 2)
		return (0);
	parse_args(ac, av);
	tab = fill_tab(ac, av);
	if (parse_duplicates(tab, ac - 1) == 1)
		error_exit();
	stack_a = new_stack_a(tab, ac - 1);
	stack_b = NULL;
	reverse_rotate(stack_a);
	reverse_rotate(stack_a);
	reverse_rotate(stack_a);
	tmp = stack_a;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	// tmp = stack_b;
	// while (tmp != NULL)
	// {
	// 	printf("%d\n", tmp->num);
	// 	tmp = tmp->next;
	// }
	printf("size = %d\n", ft_stacksize(stack_a));
	// printf("size = %d\n", ft_stacksize(stack_b));
	// (void) stack_a;
	free_stack(stack_a);
	free(tab);
	return (0);
}