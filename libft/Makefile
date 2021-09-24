# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 02:16:17 by akhalidy          #+#    #+#              #
#    Updated: 2021/09/16 19:56:47 by akhalidy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

NAME = libft.a

CC = gcc

SRC  =	ft_strlen.c ft_strncmp.c ft_calloc.c\
		ft_atoi.c ft_itoa.c ft_isdigit.c ft_isinteger.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		get_next_line_outils.c get_next_line.c ft_bzero.c \
		ft_strlcpy.c  ft_strdup.c\
		circular_db_lst.c print_circular_db_lst.c\

OBJ  = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ):
	@$(CC) $(CFLAGS) -c $(SRC)
	@echo libft.a done

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
