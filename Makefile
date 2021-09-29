# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 12:31:29 by akhalidy          #+#    #+#              #
#    Updated: 2021/09/29 17:08:13 by akhalidy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

NAME = philo

NAME_BONUS = philo_bonus

SRCS = 	philo.c ft_sleep.c ft_get_time_ms.c ft_print_status.c ft_fill_struct.c\
		ft_initialize_mutex.c ft_create_threads.c ft_free.c ft_pick_forks.c\
		ft_check_error.c\
		ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_atoi.c \

SRCS_BONUS =

CFLAGS = -Wall -Wextra -Werror -pthread

all		: $(NAME)

$(NAME)	:	$(SRCS)
			@gcc $(CFLAGS) $(SRCS) -o $(NAME)
			@echo $(NAME) was created !
clean	:
			@rm -f $(NAME)
		
fclean	: clean

re		: clean all

bonus	: $(NAME_BONUS)

$(NAME_BONUS) : $(SRCS_BONUS)
			@gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)
			@echo $(NAME_BONUS) was created !