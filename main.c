#include "push_swap.h"

int	main(int ac, char **av)
{
	// int		*tab;
	t_stack	*stack_a;
	t_stack	*stack_b;
	// char	**args;

	// args = ft_split(ac - 1, av);
	// if (!args)
	// 	return (1);
	// if (ac < 3)
	// 	return (0);
	// // printf("%s\n", args[0]);
	// // printf("%s\n", args[1]);
	// // printf("%s\n", args[2]);
	// // printf("%s\n", args[3]);
	// tab = fill_tab(ac, args);
	// if (parse_duplicates(tab, ac - 1) == 1)
	// 	error_exit();

	stack_a = new_stack_a(ac - 1, av);
	stack_b = NULL;

	// t_stack	*tmp;
	// tmp = stack_a;
	// while (tmp != NULL)
	// {
	// 	printf("%d\n", tmp->num);
	// 	tmp = tmp->next;
	// }
	// tmp = stack_b;
	// while (tmp != NULL)
	// {
	// 	printf("%d\n", tmp->num);
	// 	tmp = tmp->next;
	// }
	// printf("size = %d\n", ft_stacksize(stack_a));
	// printf("size = %d\n", ft_stacksize(stack_b));
	choose_sort(&stack_a, &stack_b);
	write_instruction(" ");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}