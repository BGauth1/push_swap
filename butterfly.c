/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:03:50 by gbertet           #+#    #+#             */
/*   Updated: 2023/03/29 15:04:14 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunks_size(t_stack *sa)
{
	int	stack_size;

	stack_size = ft_stacksize(sa);
	if (stack_size <= 50)
		return (6);
	if (stack_size <= 150)
		return (stack_size / 5);
	return (stack_size / 11);
}

void	rotate_to_nearest(t_stack *s, int inf, int sup, char instruction)
{
	int		mvtop;
	int		mvbot;
	t_stack	*tmp;

	mvtop = 0;
	mvbot = 1;
	tmp = s;
	while (tmp->num < inf || tmp->num >= sup)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return ;
		mvtop++;
	}
	tmp = s;
	while (tmp != NULL)
	{
		if (tmp->num >= inf && tmp->num < sup)
			mvbot = 1;
		else
			mvbot++;
		tmp = tmp->next;
	}
	rotate_multiple(s, mvtop, mvbot, instruction);
}

static void	push_chunk(t_stack **stack_a, t_stack **stack_b, int inf, int sup)
{
	int		med;
	int		n;
	int		i;
	t_stack	*tmp;

	med = (sup - inf) / 2 + inf;
	i = 0;
	while (ft_stacksize(*stack_b) < sup)
	{
		tmp = *stack_a;
		n = tmp->num;
		if (n >= inf && n < sup)
		{
			push(stack_b, stack_a, 'b');
			if (n < med)
				rotate(*stack_b, 'b');
			i++;
		}
		else
			rotate_to_nearest(*stack_a, inf, sup, 'a');
	}
}

void	sort_butterfly(t_stack **stack_a, t_stack **stack_b)
{
	int	inf;
	int	sup;
	int	max;
	int	incr;

	incr = chunks_size(*stack_a);
	inf = incr * -1;
	sup = 0;
	max = ft_stacksize(*stack_a) - 1;
	while (ft_stacksize(*stack_a) != 0)
	{
		inf += incr;
		sup += incr;
		if (sup >= max)
			sup = max + 1;
		push_chunk(stack_a, stack_b, inf, sup);
	}
	while (ft_stacksize(*stack_b) != 0)
	{
		rotate_to_nearest(*stack_b, max, max + 1, 'b');
		push(stack_a, stack_b, 'a');
		max--;
	}
}
