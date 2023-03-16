#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
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
t_stack	*new_stack_a(int *tab, int length);

//			INSTRUCTIONS.C			//
void	swap(t_stack *stack, char instruction);
void	push(t_stack **s1, t_stack **s2, char instruction);
void	rotate(t_stack *stack, char instruction);
void	reverse_rotate(t_stack *stack, char instruction);

//			FREE.C					//
void    free_stack(t_stack *stack);

//			ARRRAY.C				//
int	*fill_tab(int ac, char **av);
int	parse_duplicates(int *tab, int length);
int	num_position(int *tab, int num, int length);

//			PARSING.C				//
void	error_exit(void);
void	parse_args(int ac, char **av);

//			tmp_libft.c //
int	ft_atoi(const char *s);
int	ft_strlcpy(char *dst, const char *src, int size);
int	ft_strlen(const char *s);

//			WRITE_INSTRUCTION.C		//
void	write_instruction(char *instruction);

#endif