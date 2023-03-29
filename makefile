NAME = push_swap

SRC = main.c \
	stack_utils.c \
	instructions.c \
	free.c \
	array.c \
	parsing.c \
	libft.c \
	write_instruction.c \
	small_sort.c \
	butterfly.c \
	ft_split.c

OBJ = $(notdir $(SRC:.c=.o))

CFLAGS = -Werror -Wall -Wextra
CC = clang
all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
