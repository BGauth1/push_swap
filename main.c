#include "push_swap.h"

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
	rotate(stack_a, 'a');
	push(&stack_b, &stack_a, 'b');
	push(&stack_a, &stack_b, 'a');
	write_instruction(" ");
	tmp = stack_a;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	tmp = stack_b;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	printf("size = %d\n", ft_stacksize(stack_a));
	printf("size = %d\n", ft_stacksize(stack_b));
	// (void) stack_a;
	free_stack(stack_a);
	free(tab);
	return (0);
}