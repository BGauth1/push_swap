#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	ft_free_split(char **s)
{
	int i;
	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}