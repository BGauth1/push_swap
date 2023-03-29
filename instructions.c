/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:06:52 by gbertet           #+#    #+#             */
/*   Updated: 2023/03/29 15:06:55 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char instruction)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	if (instruction == 'a')
		write_instruction("sa\n");
	else
		write_instruction("sb\n");
}

void	push(t_stack **s1, t_stack **s2, char instruction)
{
	t_stack	*tmp;

	if (!*s2)
		return ;
	tmp = *s2;
	*s2 = tmp->next;
	tmp->next = *s1;
	*s1 = tmp;
	if (instruction == 'a')
		write_instruction("pa\n");
	else
		write_instruction("pb\n");
}

void	rotate(t_stack *stack, char instruction)
{
	int	tmp;

	tmp = stack->num;
	while (stack->next != NULL)
	{
		stack->num = stack->next->num;
		stack = stack->next;
	}
	stack->num = tmp;
	if (instruction == 'a')
		write_instruction("ra\n");
	else
		write_instruction("rb\n");
}

void	reverse_rotate(t_stack *stack, char instruction)
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
	if (instruction == 'a')
		write_instruction("rra\n");
	else
		write_instruction("rrb\n");
}

void	rotate_multiple(t_stack *s, int mvtop, int mvbot, char instruction)
{
	if (mvtop <= mvbot)
	{
		while (mvtop > 0)
		{
			rotate(s, instruction);
			mvtop--;
		}
	}
	else
	{
		while (mvbot > 0)
		{
			reverse_rotate(s, instruction);
			mvbot--;
		}
	}
}
