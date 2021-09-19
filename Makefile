# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 12:31:29 by akhalidy          #+#    #+#              #
#    Updated: 2021/09/19 13:12:19 by akhalidy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

NAME = philo

NAME_BONUS = philo_bonus

SRCS = main.c

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