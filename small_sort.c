/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:14:44 by gbertet           #+#    #+#             */
/*   Updated: 2023/03/29 15:14:46 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_stack *sa)
{
	if (sa->num > sa->next->num)
		swap(sa, 'a');
}

static void	sort_3(t_stack *sa)
{
	if (sa->num < sa->next->next->num && sa->next->num > sa->next->next->num)
	{
		swap(sa, 'a');
		rotate(sa, 'a');
	}
	else if (sa->num > sa->next->num && sa->num < sa->next->next->num)
		swap(sa, 'a');
	else if (sa->num > sa->next->next->num && sa->next->num > sa->num)
		reverse_rotate(sa, 'a');
	else if (sa->num > sa->next->num && sa->next->next->num > sa->next->num)
		rotate(sa, 'a');
	else if (sa->num > sa->next->num && sa->next->num > sa->next->next->num)
	{
		swap(sa, 'a');
		reverse_rotate(sa, 'a');
	}
}

static void	sort_4(t_stack **sa, t_stack **sb)
{
	rotate_to_nearest(*sa, 0, 1, 'a');
	push(sb, sa, 'b');
	sort_3(*sa);
	push(sa, sb, 'a');
}

static void	sort_5(t_stack **sa, t_stack **sb)
{
	rotate_to_nearest(*sa, 0, 2, 'a');
	push(sb, sa, 'b');
	rotate_to_nearest(*sa, 0, 2, 'a');
	push(sb, sa, 'b');
	sort_3(*sa);
	if ((*sb)->num < (*sb)->next->num)
		swap(*sb, 'b');
	push(sa, sb, 'a');
	push(sa, sb, 'a');
}

void	choose_sort(t_stack **sa, t_stack **sb)
{
	int	stack_size;

	stack_size = ft_stacksize(*sa);
	if (stack_size == 2)
		sort_2(*sa);
	else if (stack_size == 3)
		sort_3(*sa);
	else if (stack_size == 4)
		sort_4(sa, sb);
	else if (stack_size == 5)
		sort_5(sa, sb);
	else if (stack_size > 5)
		sort_butterfly(sa, sb);
}
