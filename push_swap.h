#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int 			num;
	struct s_stack	*next;
}					t_stack;

//			STACK_UTILS.C			//
int		ft_stacksize(t_stack *stack);
t_stack *new_stack(int data);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);

//			INSTRUCTIONS.C			//
void	swap(t_stack *stack);
void	push(t_stack **s1, t_stack **s2);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

//			FREE.C					//
void    free_stack(t_stack *stack);

#endif