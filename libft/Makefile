# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 14:10:01 by mmonarch          #+#    #+#              #
#    Updated: 2021/10/01 13:10:35 by mmonarch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

HEADER = libft.h

SRC =	ft_memset.c		ft_isalpha.c	ft_bzero.c\
		ft_memcpy.c		ft_memccpy.c	ft_memmove.c\
		ft_memchr.c		ft_memcmp.c		ft_strlen.c\
		ft_isdigit.c	ft_isalnum.c	ft_isascii.c\
		ft_isprint.c	ft_toupper.c	ft_tolower.c\
		ft_strchr.c		ft_strchr.c		ft_strrchr.c\
		ft_strncmp.c	ft_isnotprint.c	ft_strlcpy.c\
		ft_strlcat.c	ft_strnstr.c	ft_atoi.c\
		ft_calloc.c		ft_strdup.c		ft_substr.c\
		ft_strjoin.c	ft_itoa.c		ft_strtrim.c\
		ft_strmapi.c	ft_putchar_fd.c	ft_putendl_fd.c\
		ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c\
		get_next_line.c\
		srcprintf/ft_printf.c	\
		srcprintf/ft_parsing_flag.c	\
		srcprintf/ft_type.c\
		srcprintf/ft_print_d.c\
        srcprintf/ft_all.c\
     	srcprintf/ft_add_flag.c\
        srcprintf/ft_print_negative.c\
        srcprintf/ft_print_s.c\
        srcprintf/ft_print_c.c\
        srcprintf/ft_print_ptr.c\
        srcprintf/ft_print_u.c\
        srcprintf/ft_for_hex.c\
        srcprintf/ft_print_XXX.c

SRC_B = ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
		ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
		ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

OBJ =	$(patsubst %.c,%.o,$(SRC))
OBJ_B = $(patsubst %.c,%.o,$(SRC_B))

FLAGS =	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

bonus: $(OBJ_B) $(NAME)
	ar rcs $(NAME) $?

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY :	all bonus clean fclean re




