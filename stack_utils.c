#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack *new_stack(int data)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->num = data;
    new->next = NULL;
    return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	int	i;

	i = ft_stacksize(stack) - 1;
	while (i > 0)
	{
		stack = stack->next;
		i--;
	}
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		tmp = ft_stacklast(*stack);
		tmp->next = new;
	}
}
