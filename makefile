NAME = push_swap

SRC = main.c \
	stack_utils.c \
	instructions.c \
	free.c \
	array.c \
	parsing.c \
	tmp_libft.c \
	write_instruction.c

# SRCBONUS = ft_lstnew.c \
# 		ft_lstadd_front.c \
# 		ft_lstsize.c \
# 		ft_lstlast.c \
# 		ft_lstadd_back.c \
# 		ft_lstdelone.c \
# 		ft_lstclear.c \
# 		ft_lstiter.c \
# 		ft_lstmap.c \

# ifdef BONUS
# 	SRC += SRCBONUS
# endif

OBJ = $(notdir $(SRC:.c=.o))

# OBJBONUS = $(notdir $(SRCBONUS:.c=.o))

# CFLAGS = -Werror -Wall -Wextra
CC = gcc
all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

# bonus : $(OBJBONUS)
# 	ar -rc $(NAME) $(OBJBONUS)

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
