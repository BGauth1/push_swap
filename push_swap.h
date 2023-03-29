/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:12:44 by gbertet           #+#    #+#             */
/*   Updated: 2023/03/29 15:12:46 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

//			ARRRAY.C				//
int			*fill_tab(int *ac, char **av);
int			num_position(int *tab, int num, int length);

//			BUTTERFLY.C				//
void		sort_butterfly(t_stack **stack_a, t_stack **stack_b);
void		rotate_to_nearest(t_stack *s, int inf, int sup, char instruction);

//			FREE.C					//
void		free_stack(t_stack *stack);
void		ft_free_split(char **s);

//			FT_SPLIT.C				//
char		**ft_split(int ac, char **av);

//			INSTRUCTIONS.C			//
void		swap(t_stack *stack, char instruction);
void		push(t_stack **s1, t_stack **s2, char instruction);
void		rotate(t_stack *stack, char instruction);
void		reverse_rotate(t_stack *stack, char instruction);
void		rotate_multiple(t_stack *s, int mvtop, int mvbot, char instruction);

//			LIBFT.C					//
long long	ft_atoi(const char *s);
int			ft_strlcpy(char *dst, const char *src, int size);
int			ft_strlen(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strdup(const char *s);

//			PARSING.C				//
void		error_exit(void);
int			parse_args(char *s);
char		*parse_join(int ac, char **av);
int			is_space(char c);

//			SMALL_SORT.C			//
void		choose_sort(t_stack **stack_a, t_stack **stack_b);

//			STACK_UTILS.C			//
int			ft_stacksize(t_stack *stack);
t_stack		*ft_stacklast(t_stack *stack);
t_stack		*new_stack_a(int length, char **av);

//			WRITE_INSTRUCTION.C		//
void		write_instruction(char *instruction);

#endif
