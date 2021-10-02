# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 12:31:29 by akhalidy          #+#    #+#              #
#    Updated: 2021/10/01 21:46:42 by akhalidy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = philo

SRCS = 	philo.c ft_sleep.c ft_get_time_ms.c ft_print_status.c ft_fill_struct.c\
		ft_initialize_mutex.c ft_create_threads.c ft_free.c ft_pick_forks.c\
		ft_check_error.c\
		ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_atoi.c \

CFLAGS = -Wall -Wextra -Werror -pthread

all		: $(NAME)

$(NAME)	:	$(SRCS)
			@gcc $(CFLAGS) $(SRCS) -o $(NAME)
			@echo $(NAME) was created !
clean	:
			@rm -f $(NAME)
		
fclean	: clean

re		: clean all
