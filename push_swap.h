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
t_stack	*new_stack_a(int length, char **av);

//			INSTRUCTIONS.C			//
void	swap(t_stack *stack, char instruction);
void	push(t_stack **s1, t_stack **s2, char instruction);
void	rotate(t_stack *stack, char instruction);
void	reverse_rotate(t_stack *stack, char instruction);
void	rotate_multiple(t_stack *s, int mvtop, int mvbot, char instruction);

//			FREE.C					//
void    free_stack(t_stack *stack);
void	ft_free_split(char **s);

//			ARRRAY.C				//
int		*fill_tab(int *ac, char **av);
int		parse_duplicates(int *tab, int length);
int		num_position(int *tab, int num, int length);

//			PARSING.C				//
void	error_exit(void);
int		parse_args(char *s);
char	*parse_join(int ac, char **av);
int		is_space(char c);

//			tmp_libft.c //
long long	ft_atoi(const char *s);
int			ft_strlcpy(char *dst, const char *src, int size);
int			ft_strlen(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strdup(const char *s);

//			WRITE_INSTRUCTION.C		//
void	write_instruction(char *instruction);

//			SMALL_SWAP.C			//
void    choose_sort(t_stack **stack_a, t_stack **stack_b);
void    sort_2(t_stack *sa);
void    sort_3(t_stack *sa);
void    sort_4(t_stack **sa, t_stack **sb);
void    sort_5(t_stack **sa, t_stack **sb);

//			BUTTERFLY.C				//
void    sort_butterfly(t_stack **stack_a, t_stack **stack_b);
int     check_sorted(t_stack *stack_a, t_stack *stack_b);
void	rotate_to_nearest(t_stack *s, int inf, int sup, char instruction);
void	push_chunk(t_stack **stack_a, t_stack **stack_b, int inf, int sup);

//			FT_SPLIT.C				//
char	**ft_split(int ac, char **av);

#endif