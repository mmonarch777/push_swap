NAME = push_swap

HEADER = push_swap.h

SRC =	push_swap.c		error.c			ft_check_digit.c		ft_add_and_handling.c		ft_push_to_stack.c\
		ft_swap.c		ft_rotate.c		ft_revers_rotate.c		ft_index.c					ft_markup.c\
		ft_sort.c		ft_need_swap.c

OBJ = $(patsubst %.c,%.o,$(SRC))

#FLAGS = -Wall -Werror -Wextra

all: libft  $(NAME)

$(NAME): $(OBJ) $(HEADER)
		gcc -Llibft -lft $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -c $< -o $@

libft:
		make -C libft/

clean:
		rm -f $(OBJ)
		make clean -C libft/

fclean: clean
		rm -f $(NAME)
		rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re libft mlx