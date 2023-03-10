#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	push(t_stack **s1, t_stack **s2)
{
	t_stack	*tmp;

	tmp = *s2;
	*s2 = tmp->next;
	tmp->next = *s1;
	*s1 = tmp;
}

void	rotate(t_stack *stack)
{
	int	tmp;

	tmp = stack->num;
	while (stack->next != NULL)
	{
		stack->num = stack->next->num;
		stack = stack->next;
	}
	stack->num = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	tmp1;
	int	tmp2;

	tmp1 = stack->num;
	stack->num = ft_stacklast(stack)->num;
	stack = stack->next;
	while (stack != NULL)
	{
		tmp2 = stack->num;
		stack->num = tmp1;
		tmp1 = tmp2;
		stack = stack->next;
	}
}