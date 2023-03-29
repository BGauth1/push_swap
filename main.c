#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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