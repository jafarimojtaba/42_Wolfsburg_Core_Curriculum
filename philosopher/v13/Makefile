# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 18:20:50 by mjafari           #+#    #+#              #
#    Updated: 2022/06/23 18:42:11 by mjafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDES = philo.h
SRC = main.c init.c utils.c actions.c

OBJ = $(SRC:.c=.o)

all: fclean $(NAME)

$(NAME):
	$(CC) -lpthread -Wall -Werror -Wextra $(SRC) -o $(NAME) -g -fsanitize=thread

clean: 
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all
